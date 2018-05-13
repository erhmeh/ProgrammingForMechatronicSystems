#include "RangerFusion.h"

using namespace std;

const string kDefaultFusion = "average";


RangerFusion::RangerFusion(string fusionMethod)
{
    setFusionMethod(fusionMethod);
}

void RangerFusion::setRangers(vector<Ranger*> rangers)
{
    _rangers = rangers;
}

bool RangerFusion::setFusionMethod(string fusionMethod)
{
    if(validateFusionMethod(fusionMethod) == true) _fusionMethod = fusionMethod;
    else _fusionMethod = kDefaultFusion;

    return validateFusionMethod(fusionMethod);
}

string RangerFusion::getFusionMethod()
{
    return _fusionMethod;
}


vector<vector<double> > RangerFusion::getRawRangeData()
{
    _rawRangeData.clear();
    for(auto ranger : _rangers){
        _rawRangeData.emplace_back(ranger->getRandOutput());
    }
    return _rawRangeData;
}


bool RangerFusion::validateFusionMethod(string fusionMethod)
{
    if(fusionMethod == "max" || fusionMethod == "min" || fusionMethod == "average")return true;
    else return false;
}

// Determine which Ranger is the reference using the getAngularOffset methods
// Sort the _rangers container and the rawData container so that the reference Ranger (Ranger with the smallest
// offset) moves to the front
void RangerFusion::compareRangeData()
{ 

    // make a copy of of the Ranger pointers so that they can be sorted
    vector<Ranger*> rangers = _rangers;

    // make a copy of the raw data so that they can be sorted
    vector<vector<double> >rawData = _rawRangeData;


    // Sort these vectors by the Angular offset of their object and then by the number of samples if two objects have
    // the same Angular offset values

    bool did_swap = true;
    while(did_swap) {
        did_swap = false;
        for (unsigned int i = 1; i < rangers.size(); i++) {
            // if this pair is out of order
            if (rangers.at(i-1)->getAngularOffset() > rangers.at(i)->getAngularOffset()) {
                // swap the pointers in Rangers vector
                auto tempRangers = rangers.at(i);
                rangers.at(i) = rangers.at(i - 1);
                rangers.at(i - 1) = tempRangers;

                // swap the data sets that correspond the the pointer being swapped
                auto tempRawData = rawData.at(i);
                rawData.at(i) = rawData.at(i - 1);
                rawData.at(i - 1) = tempRawData;

                // remember that something has changed
                did_swap = true;
            }
            // if Angular offsets match, compare based on number of Samples
            else if (rangers.at(i-1)->getNumSamples() < rangers.at(i)->getNumSamples()){
                // swap the pointers in Rangers vector
                auto tempRangers = rangers.at(i);
                rangers.at(i) = rangers.at(i - 1);
                rangers.at(i - 1) = tempRangers;

                // swap the data sets that correspond the the pointer being swapped
                auto tempRawData = rawData.at(i);
                rawData.at(i) = rawData.at(i - 1);
                rawData.at(i - 1) = tempRawData;

                // remember that something has changed
                did_swap = true;
            }
        }
        _sortedRangers = rangers;
        _sortedRawData = rawData;
    }


    // Determine the properties of the Ranger the will be used as the reference for the fusion
    // As a result of the above sort, this will be the first element in _sortedRangers
    int refNumSamples = _sortedRangers.at(0)->getNumSamples();
    int refAngularRes = _sortedRangers.at(0)->getAngularRes();
    double refAngularOffset = _sortedRangers.at(0)->getAngularOffset();

    // Each vector<double> within this private member vector will contain a group of samples that correspond to a
    // sample bearing of the reference Ranger. These groups will then be fused later on.
    // This vectors size will be equal to the reference Rangers number of sample bearings.
    _fusionSets.clear();

    // Vector used to move the individual values, from the raw data container into their own vector<double>
    // so that they can be inserted into the fusionSets vector<vector<double> > as an element
    vector<double> tempSample;

    // Add each sample into the corresponding fusion set and load the Reference Rangers sample bearings into
    // a container so that they can be used to compare the Reference Ranger to the other received Ranger data
    _refRangerBearings.clear();
    for(int sampleNum = 0; sampleNum < refNumSamples; sampleNum++){
        tempSample.push_back(_sortedRawData[0][sampleNum]);
        _fusionSets.push_back(tempSample);
        tempSample.clear();

        _refRangerBearings.push_back(refAngularOffset + (refAngularRes * sampleNum));
    }

    // Loop through the remaining Rangers, determine their properties and compare their samples to the
    // reference Ranger. The current Ranger under inspection will be referred to as the targetRanger
    for(int targetRangerLocation = 1; targetRangerLocation < _sortedRangers.size(); targetRangerLocation++){
        // Determine the properties of Ranger number at rangerLocation
        int targetRangerNumSamples = _sortedRangers.at(targetRangerLocation)->getNumSamples();
        int targetRangerFieldOfView = _sortedRangers.at(targetRangerLocation)->getFieldOfView();
        int targetRangerAngularRes = _sortedRangers.at(targetRangerLocation)->getAngularRes();
        double targetRangerAngularOffset = _sortedRangers.at(targetRangerLocation)->getAngularOffset();

        // Load the bearings of Ranger at rangerLocation into a vector so that we can compare them with the reference
        vector<double> targetRangerBearings;
        targetRangerBearings.clear();
        for(int targetRangerSampleNum = 0; targetRangerSampleNum < targetRangerNumSamples; targetRangerSampleNum ++){
            targetRangerBearings.push_back(targetRangerAngularOffset + targetRangerSampleNum * targetRangerAngularRes);
        }

        // ////////////////////////////////////////////////////////////////////////////////
        // Determine whether Ranger returns point objects (laser) or areas (radar)
        // ////////////////////////////////////////////////////////////////////////////////


        // For each reference bearing, loop through the Ranger under inspection and compare the reference
        // bearing to the areas defined by each radar bearing and its angular resolution
        for(int refBearingNum = 0; refBearingNum < _refRangerBearings.size(); refBearingNum++){
            for(int targetBearingNum = 0; targetBearingNum < targetRangerBearings.size(); targetBearingNum ++){

                double refBearing = _refRangerBearings.at(refBearingNum);
                double targetBearing = targetRangerBearings.at(targetBearingNum);

                // If the Ranger fullfills this condition, then it takes measurements over an area in space (RADAR)
                if(targetRangerNumSamples = targetRangerFieldOfView/targetRangerAngularRes){

                    // If the Reference Bearing overlaps with the Target Radar area (sector), defined by the current target
                    // bearing, then add the Radar sample taken at this bearing to the fusion set (in fusionSets)
                    // that corresponds this Reference Bearing.
                    if(refBearing >= (targetBearing - targetRangerAngularRes/2)
                            && refBearing  <= (targetBearing + targetRangerAngularRes/2)){

                        // Obtain the target sample from the target Rangers data vector in _sortedRawData vector<vector<double> >
                        double targetSample = _sortedRawData.at(targetRangerLocation).at(targetBearingNum);

                        // Load the target sample into the fusion set that corresponds to the current reference bearing
                        // that is under inspection
                        _fusionSets.at(refBearingNum).push_back(targetSample);
                    }
                }

                // If the Ranger fullfills this condition, then it takes measurements at a point (LASER)
                else if (targetRangerNumSamples = 1 + targetRangerFieldOfView/targetRangerAngularRes){

                    // If the Reference Bearing is equal to the Target Bearing, then add the Laser sample taken at this bearing
                    // to the fusion set (in fusionSets) that corresponds this Reference Bearing.
                    if(refBearing == targetBearing){

                        // Obtain the target sample from the target Rangers data vector in _sortedRawData vector<vector<double> >
                        double targetSample = _sortedRawData.at(targetRangerLocation).at(targetBearingNum);

                        // Load the target sample into the fusion set that corresponds to the current reference bearing
                        // that is under inspection
                        _fusionSets.at(refBearingNum).push_back(targetSample);
                    }
                }
            }
        }
    }
}

vector<double> RangerFusion:: getFusedRangeData()
{
    // Determines which Ranger is the Reference Ranger and compares their raw data and
    // groups overlapping into vectors which are contained within _fusionSets
    compareRangeData();

    // Clear the current contents of _fusedRangeData
    _fusedRangeData.clear();

    // get the maximum range of the Reference Ranger
    double refRangerMaxRange = _sortedRangers.at(0)->getMaxRange();

    // If the Reference Ranger (Laser) is the minimum value in the fusion set, of size greater than 1, for a
    // particular bearing, and it is also at is max value, i.e. there is no obstacle deteced within its maximum
    // range, then this laser value should be omitted from the fusion, as it will skew the result
    for(vector<double> dataSet : _fusionSets){
        // Start with the first value (the value taken from the Reference Ranger)
        double minValue = dataSet[0];

        // Compare the remaining values to the first value
        for(int value = 1; value < dataSet.size(); value++){
            if(dataSet[value] < minValue) {
                minValue = dataSet[value];
            }
        }

        // If the Reference Ranger is maxing out and is the minimum value in a data set of size greater than 1
        // erase the value
        if(minValue == dataSet[0] && minValue == refRangerMaxRange && dataSet.size() > 1 ){
            dataSet.erase(dataSet.begin());
        }
    }

    // Proceed with the fusion of the remaining elements
    if(_fusionMethod == "min"){

        // Re-calculate the minimum value in each data set and add this value to the _fusedRangeData vector
        for(vector<double> dataSet : _fusionSets){

            // Start with the first value in the dataSet
            double minValue = dataSet[0];

            // Compare the remaining values to the first value
            for(int value = 1; value < dataSet.size(); value++){
                if(dataSet[value] < minValue) {
                    minValue = dataSet[value];
                }
            }
            _fusedRangeData.push_back(minValue);
        }
    }

    else if(_fusionMethod == "max"){
        // Determine the maximum value in each data set and add this value to the _fusedRangeData vector
        for(vector<double> dataSet : _fusionSets){

            // Start with the first value in the dataSet
            double maxValue = dataSet[0];

            // Compare the remaining values to the first value
            for(int value = 1; value < dataSet.size(); value++){
                if(dataSet[value] > maxValue) {
                    maxValue = dataSet[value];
                }
            }
            _fusedRangeData.push_back(maxValue);
        }

    }

    else if(_fusionMethod == "average"){
        // Determine the average of the values within each dataSet and this average to the _fusedRangeData vector
        for(vector<double> dataSet : _fusionSets){

            // A double that will hold the numerator value
            double sum = 0.0;

            // Calculate the sum of the samples in the data set
            for(int value = 0; value < dataSet.size(); value++){
                 sum += dataSet[value];
            }

            // Calculate the average
            double average = sum/dataSet.size();;
            _fusedRangeData.push_back(average);
        }
    }
    return _fusedRangeData;
}







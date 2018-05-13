#ifndef RANGERFUSION_H
#define RANGERFUSION_H
#include "RangerFusionInterface.h"

// RangerFusion inherits from RangerFusionInterface and implements its pure virtual methods
class RangerFusion : public RangerFusionInterface
{
private:
    string _fusionMethod;
    vector<Ranger*> _rangers;
    vector<Ranger*> _sortedRangers;


    bool validateFusionMethod(string fusionMethod);


    vector<vector<double> > _rawRangeData;
    vector<vector<double> > _sortedRawData;
    vector<double> _refRangerBearings; // vector that will store the bearings of the reference rangers samples
    vector<vector<double> > _fusionSets;
    vector<double> _fusedRangeData;

    void compareRangeData();


public:
    RangerFusion(string fusionMethod);

    bool setFusionMethod(string fusionMethod);
    string getFusionMethod();

    // Accepts container of rangers as per requirement C2 of assignment 2
    void setRangers(vector<Ranger*> rangers);

    // a vector of vectors used to store the raw data sets from each sensor and
    // stores it in a private memeber. Must be called before getFusedData so that private
    // member _rawRangeData is updated
    vector<vector<double> > getRawRangeData();

    // Takes the groups of data stored in _fusionSets, which were processed by compareRangeData(),
    // and fuses them depending on the current fusion method (set on construction)
    vector<double> getFusedRangeData();


};

#endif // RANGERFUSION_H

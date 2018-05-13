#include "rangerfusioninterface.h"
#include <map>
#include <iostream>
#include "ranger.h"
#include "laser.h"
#include "radar.h"

//ranger fusion interface constructor
RangerFusionInterface::RangerFusionInterface(){
//    vector<Ranger*> fusionData_;
}

// Accepts container of rangers as per requirement C2 of assignment 2
void RangerFusionInterface::setRangers(vector<Ranger*> rangers){
    fusionData_ = rangers;

    //fault finding checks
    if(fusionData_.empty()){
        std::cout<<"fusionData was not filled"<<endl;
    }
    else{
        std::cout<<"fusionData was filled"<<endl;
    }

}

//// Returns a container of fused range readings as per C4 assignment 2
vector<double> getFusedRangeData(){
    //NOTE: keys reflect bearings
    //iterate through all doubles of each matching key across the data polled from each ranger, comparing for the min or max, or creating an average
    //MAX: tempMax=0, if rangerfirst.data(key 10*).begin>tempMax, tempMax = ranger.data(key 10*).begin
    //  continue this through to rangerlast.data(key 10*).end. then fusedData(key 10*)=tempMax

    //THEN do for rangerall.data(key 20*) etc until last key. Similar for MIN.

    //AVARAGE: tempAvg=0, tempAvg=tempAvg+rangerfirst.data(key 10*).begin, iterating through all data attached to key 10* for all rangers
    // tempAvg/sumSize, sumSize=rangerfirst(key 10*).size()+rangersecond(key 10*).size().....+rangerlast(key 10*).size()
    //repeat for all existing keys
}


//// Returns a container of raw/unfused range readings as per C5 assignment 2
vector<vector<double> > RangerFusionInterface::getRawRangeData(){
    //fault finding check
    if(fusionData_.empty()){
        std::cout<<"fusionData is empty"<<endl;
    }

    //required local variables
    vector<vector<double>> rawData;
    std::map<int, vector<double>> collatedMap;

    //nested loops that go through the data from each ranger object and put into a collated map
    for(auto ranger : fusionData_){
//        std::cout<<"c1"<<std::endl;

        for(auto polledMap : ranger->poll()){
//            std::cout<<"c2"<<std::endl;

            for(auto polledValueDouble : polledMap.second){ //Pretty sure just use polledMap
//                std::cout<<"c3"<<endl; //polledValueDouble is a double
                collatedMap[(polledMap.first)].push_back(polledValueDouble);
            }

        }
    }

//    std::cout<<"c4"<<std::endl;

    //loop that puts info from collated map into rawData of vector<vector<double>> that the function needs to return
    for(auto data: collatedMap){

        if(!data.second.empty()){
            rawData.push_back(data.second);
            for(int i = 0; i<data.second.size(); i++){
            std::cout<<"values@: " <<data.first<<" = " <<data.second.at(i)<<std::endl;
            }
        }
    }
    std::cout<<"getRawRangeData complete"<<std::endl;

    return rawData;
}

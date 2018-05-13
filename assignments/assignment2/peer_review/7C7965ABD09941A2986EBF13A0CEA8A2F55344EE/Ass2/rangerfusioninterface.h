#ifndef RANGERFUSIONINTERFACE_H
#define RANGERFUSIONINTERFACE_H

#include <vector>
#include "ranger.h"
using std::vector;



//i acknowledge that i should not have changed this header, instaed creatoing a derived class called fusion, that uses these function members
//however i ran out of time to rectify this misunderstanding. had there been a dervied class with functions of the same signature
//these functions would have been declared as virtual





// This is a forward declaration of the Ranger class (google it)
// It tells the RangerFusionInterface that such a class exists
// but does not specify its details
class Ranger;

// The RangerFusionInterface is a class which specifies the minimum
// required interface for your RangerFusion class your ranger fusion
// class must inherit from it
class RangerFusionInterface
{
public:
    vector<Ranger*> fusionData_;
    RangerFusionInterface();

    // Accepts container of rangers as per requirement C2 of assignment 2
    void setRangers(vector<Ranger*> rangers);

    // Returns a container of fused range readings as per C4 assignment 2
    vector<double> getFusedRangeData();

    // Returns a container of raw/unfused range readings as per C5 assignment 2
    vector<vector<double> > getRawRangeData();
private:
    int fusionType;

};

#endif // RANGERFUSIONINTERFACE_H


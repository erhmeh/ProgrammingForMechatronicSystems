#include <iostream>
#include "rangerfusioninterface.h"
#include "ranger.h"
#include "radar.h"
#include "laser.h"
#include <map>
#include <vector>


using namespace std;

int main()
{
    //create laser object l1(which gets user defined variables) and prints params
    Laser l1;
    l1.printParams();
    cout << "-------------------------------------" << endl;

    //create radar object r1(which gets user defined variables) and prints params
    Radar r1;
    r1.printParams();
    cout << "-------------------------------------" << endl;

    //create radar object r2(which gets user defined variables) and prints params
    Radar r2;
    r2.printParams();
    cout << "-------------------------------------" << endl;

    //create fusion object f1 and prints params
    RangerFusionInterface f1;
    //create pointers to ranger objects
    Ranger* pl1 = &l1;
    Ranger* pr1 = &r1;
    Ranger* pr2 = &r2;
    //put pointers into a vector of ranger objects
    vector<Ranger*> rangers = {pl1,pr1,pr2};
    //set vector of ranger pointer objects into f1
    f1.setRangers(rangers);
    //initialise rawRangeData vector of vector of doubles, to received returned data from RangerFusionInterface::getRawRangeData.
    vector<vector<double>> rawRangeData;
    rawRangeData = f1.getRawRangeData();
    //fault finder to ensure return from getRawRangeData isnt empty
    if(rawRangeData.empty()){
        cout<< "empty"<<endl;
    }
    cout << "END OF PROGRAM" << endl;
    return 0;
}


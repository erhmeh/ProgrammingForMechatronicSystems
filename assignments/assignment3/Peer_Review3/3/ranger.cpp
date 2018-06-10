#include "ranger.h"

using namespace std;


//Constructor

Ranger::Ranger() :model_(""),type_(eRANGER_UNKNOWN)
{}


Ranger::Ranger(string model,eRangerType type) :model_(model),type_(type)
{}

//Virtual Destructor
Ranger::~Ranger() {}


//Get functions
string Ranger::getModel()
{
    return model_;
}

int Ranger::getBaud()
{
    return baud_;
}

int Ranger::getPort()
{
    return port_;
}

double Ranger::getMaxDistance() {
    return max_distance_;
}

double Ranger::getMinDistance() {
    return min_distance_;
}

double Ranger::getFieldOfView() {
    return field_of_view_;
}


eRangerType Ranger::getType() {
    return type_;
}


double Ranger::getDataRate() {
    return data_rate_;
}





#include "trainee.h"

Trainee::Trainee(){}

Trainee::~Trainee(){}

string Trainee:: getID(){
    return trainee_ID;
}
void Trainee::setID(string new_ID){
    trainee_ID = new_ID;
}
float Trainee:: getAllowance(){
    return monthly_allowance;
}

void Trainee::setAllowance(float allowance){
    monthly_allowance = allowance;
}
float Trainee::getDuration(){
    return duration;
}
void Trainee::setDuration(float new_duration){
    duration = new_duration;
}

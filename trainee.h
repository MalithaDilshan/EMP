#ifndef TRAINEE_H
#define TRAINEE_H

#include<iostream>
#include<string>
#include "worker.h"

using namespace std;

class Trainee: public Worker{

private:
    string trainee_ID;
    float monthly_allowance;
    float duration;
public:
    Trainee();
    ~Trainee();

    string getID();
    void setID(string new_ID);
    float getAllowance();
    void setAllowance(float allowance);
    float getDuration();
    void setDuration(float new_duration);


};

#endif // TRAINEE_H

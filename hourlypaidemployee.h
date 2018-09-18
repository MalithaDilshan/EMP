#ifndef HOURLYPAIDEMPLOYEE_H
#define HOURLYPAIDEMPLOYEE_H

#include<iostream>
#include "employee.h"

using namespace std;

class HourlyPaidEmployee:public Employee{

private:
    float hour_rate;
    float number_of_hours;
    float salary;

public:
    HourlyPaidEmployee();
    ~HourlyPaidEmployee();
    //prototypes
    void setRate(float rate);
    void setHours(float hours);
    float getSalary();

};

#endif // HOURLYPAIDEMPLOYEE_H

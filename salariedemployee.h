#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include<iostream>
#include "employee.h"

using namespace std;

class SalariedEmployee:public Employee{
private:
    float salary;

public:
    SalariedEmployee();
    ~SalariedEmployee();
    // prototypes
    float getSalary();
    void setSalary(float sal);

};

#endif // SALARIEDEMPLOYEE_H

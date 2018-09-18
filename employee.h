#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include<string>
#include "worker.h"


using namespace std;

class Employee:public Worker{

private:
    string employee_ID;

public:
    Employee();
    virtual ~Employee();
    // prototypes
    string getID();
    void setID(string ID);
    // virtual functions
    virtual float getSalary();
    virtual void setSalary(float salary);
    virtual void setRate(float rate);
    virtual void setHours(float hours);

};

#endif // EMPLOYEE_H

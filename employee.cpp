#include "employee.h"

Employee::Employee(){}
Employee::~Employee(){}

string Employee::getID(){
    return employee_ID;
}
void Employee:: setID(string ID){
    employee_ID = ID;
}

// implementation for the virtual functions for the derived classes (set the salary)
float Employee:: getSalary(){
    return 0;
}

void Employee:: setSalary(float salary){}

void Employee:: setRate(float rate1){}

void Employee:: setHours(float hours1){}

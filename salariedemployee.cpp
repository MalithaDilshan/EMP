#include "salariedemployee.h"

SalariedEmployee::SalariedEmployee(){}

SalariedEmployee::~SalariedEmployee(){}

// get the salary of the employee
float SalariedEmployee:: getSalary(){
    return salary;
}
// set the salary of the employee
void SalariedEmployee::setSalary(float sal){
    salary = sal;
}

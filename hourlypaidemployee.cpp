#include "hourlypaidemployee.h"

HourlyPaidEmployee::HourlyPaidEmployee(){}

HourlyPaidEmployee::~HourlyPaidEmployee(){}

// set the hour rate
void HourlyPaidEmployee:: setRate(float rate){
    hour_rate = rate;
}
// set the number of hours that employee worked
void HourlyPaidEmployee:: setHours(float hours){
    number_of_hours = hours;
}

//calculate the salary
float HourlyPaidEmployee:: getSalary(){
    salary = hour_rate*number_of_hours;
    return salary;
}

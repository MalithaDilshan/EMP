#include "worker.h"

Worker::Worker(){}

Worker::~Worker(){}

// get name of the worker
string Worker:: getName(){
    return name;
}
// set name of the worker
void Worker:: setName(string new_name){
    name = new_name;
}
// get age of the worker
int Worker:: getAge(){
    return age;
}
// set age of the worker
void Worker:: setAge(int new_age){
    age = new_age;
}

#include <iostream>
#include<functional>
#include<string>

#include "singleton.h"


using namespace std;

Singleton::~Singleton(){
    instanceFlag = false;
}

//initiate the variables
bool Singleton::instanceFlag = false;
Singleton* Singleton::sing_object = NULL;

Singleton* Singleton::getInstance(){
    if(!instanceFlag){
        // create a instance for once
        sing_object = new Singleton();
        instanceFlag = true;  // create instance only one time
        return sing_object; // return object to use
    }
    else{
        return sing_object;  // return the previously created object
    }
}
// add a worker to the hash map via calling to the DataHandle object
void Singleton::addWorker(string command, char worker_type, char employee_type){
    Singleton::data_handler_obj->addWorker(worker_type,employee_type);
}
// get details of a particular worker via calling to the DataHandle object
void Singleton::getDetails(string command, string id_number){
    Singleton::data_handler_obj->getDetails(id_number);
}
// remove a worker from the database(Hash map) via calling to the DataHandle object
void Singleton::removeWorker(string command, string id_number){
    Singleton::data_handler_obj->removeWorker(id_number);
}
// execute other commands(without special setting) in the DataHandle class
void Singleton::executeCommand(string command){
    Singleton::data_handler_obj->executeCommand(command);

}

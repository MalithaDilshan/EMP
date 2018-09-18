// manipulate tge all command by user and access the hash map (or other specific data structure seperately

#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include<iostream>
#include<string>
#include "worker.h"
#include "trainee.h"
#include "hashmap.h"
#include "employee.h"
#include "salariedemployee.h"
#include "hourlypaidemployee.h"


using namespace std;

class DataHandler{
private:
    // create a instances for the hash maps
    HashMap<Trainee*>* trainee_data;
    HashMap<Employee*>* employee_data;
    int trainee_map_size;
    int employee_map_size;

public:
    DataHandler();
    ~DataHandler();

    void addWorker(char worker_type, char employee_type); // create a relevant object
    void getDetails(string id_number);  // get details of the worker according to the ID number
    void removeWorker(string id_number); // remove a worker according to the ID number
    void executeCommand(string command); // execute other commands
    void loadData();  // loading the data from the text file
    bool validate_key(string key); // validate the ID

};

#endif // DATAHANDLER_H

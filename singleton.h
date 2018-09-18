//**********************************************************//
// Use the singleton anti pattern access database securely. //
//**********************************************************//

#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include<string>
#include "datahandler.h"


using namespace std;

class Singleton{

private:
    static Singleton* sing_object;
    static bool instanceFlag;
    DataHandler* data_handler_obj;
    // By initiating the DataHandler object in private constructor it will initiate one time
    Singleton(){
        data_handler_obj = new DataHandler();
    }  // private constructor

public:
    ~Singleton();
    static Singleton* getInstance();
    void addWorker(string command, char worker_type, char employee_type);
    void getDetails(string command, string id_number);
    void removeWorker(string command, string id_number);
    void executeCommand(string command);

};

#endif // SINGLETON_H

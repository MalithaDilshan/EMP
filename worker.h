// main object for the worker. This can access the trainee and the employee seperately.


#include<iostream>
#include<string>

#ifndef WORKER_H
#define WORKER_H

using namespace std;
class Worker{

private:
    string name;
    int age;

public:
    Worker();
    ~Worker();

    string getName();
    void setName(string new_name);
    int getAge();
    void setAge(int new_age);

};

#endif // WORKER_H

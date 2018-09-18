// handle the all commands seperately and gives the relevent functionality for the commands

#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include<string>

using namespace std;

class Command{

private:
    string first_command;
    string id_number;
    char worker_type;
    char employee_type;

public:
    Command();

    //prototypes
    void list_commands();
    string seperate_command(string command);
    bool run_command(string command);
    void get_sub_commands();
    bool validate(string command);
};

#endif // COMMAND_H

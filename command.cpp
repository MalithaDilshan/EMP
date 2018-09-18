//*********************************************************************//
//              High level interface to access database                //
//             Analyze the command that user have entered              //
//*********************************************************************//


#include <iostream>
#include<string>
#include <ctype.h>

#include "singleton.h"
#include "command.h"

using namespace std;

Command::Command(){}

// command manual
void Command::list_commands(){
    cout << "############################## Command Manual #############################" << endl;
    cout << " " << endl;
    cout << "add              : Add a worker to the data base" << endl;
    cout << "list_all         : List the all data that have already stored " << endl;
    cout << "list_monthly_pay : List monthly pay for all employees" << endl;
    cout << "get_total_pay    : List monthly total pay of workers" << endl;
    cout << "get_details <id> : Get details for particular ID" << endl;
    cout << "remove <id>      : Remove particular ID from the database " << endl;
    cout << "exit             : Exit from the software" << endl;
    cout << "help             : Display command manual" << endl;
    cout << " " <<  endl;
    cout << "###########################################################################"<< endl;

}

// if use input "get_details <id>" or "remove <id>", this method will split the id and return it
string Command::seperate_command(string command){
    string id = "";
    int unsigned count1 = 0;
    int length = 0;
    char id1[10];
    char command1[10];
    for(unsigned int i = 0; i< command.length(); i++){
        if(isspace(command[i])){
            count1 = i;
            break;
        }
        else
            count1 = command.length();
    }

    if(count1 < (command.length()-1)){
        for(unsigned int i = 0; i< count1; i++){
            command1[i] = command[i];
        }
        command1[count1] = '\0';   // terminating character
        Command::first_command = string(command1);
        length = command.length()-(count1+1);
        for(int j = 0; j<length;j++){
            id1[j] = command[count1+1+j];

        }
        id1[length] = '\0';
        id = (string)id1;
    }
    else{
        Command::first_command = command;
    }
    return id;

}

// get sub commands
void Command::get_sub_commands(){
    string wt,et;
    while(1){
        cout << "Please enter worker type-('E' for employee, 'T' for Trainee) : " ;
        getline(cin, wt);
        if(wt == "E"){
            while(1){
                cout << "Please enter Employee type-('S' for salaried employee, 'H' for hourly paid employee) : ";
                getline(cin, et);
                if((et != "S") && (et != "H"))
                    cout << "Invalid Employee type, Please enter again! " << endl;
                else
                    break;
            }
        }
        if((wt != "E") && (wt != "T"))
            cout << "Invalid Worker type, Please enter again!" << endl;
        else
            break;

    }

    // update type
    Command::worker_type = wt[0];
    Command::employee_type = et[0];
}

// validate first command
bool Command::validate(string c){
    bool success = false;
    if(c == "help" || c == "add" || c == "list_all" || c == "exit")success = true;
    if(c == "list_monthly_pay" || c == "get_total_pay" || c == "get_details" || c == "remove")success = true;

    return success;

}

// run and analyze commands commands
bool Command::run_command(string command){
    Command::id_number=seperate_command(command);

    if(validate(Command::first_command)){
        if(Command::first_command == "exit"){   // no further functionality
            return false;
        }
        //********************************************//
        //  Access database via the singleton object  //
        //********************************************//
        Singleton *my_obj;
        my_obj = Singleton::getInstance(); // get instance

        if(Command::first_command == "add"){
            get_sub_commands();
            my_obj-> addWorker(Command::first_command, Command::worker_type, Command::employee_type);
        }
        else if(Command::first_command == "get_details"){
            my_obj-> getDetails(Command::first_command, Command::id_number);
            if(Command::id_number.empty()){
                cout << "Please enter ID number of worker to get details!" << endl;
                return true;
            }
        }
        else if(Command::first_command == "remove"){
            my_obj->removeWorker(Command::first_command, Command::id_number);
            if(Command::id_number.empty()){
                cout << "Please enter ID number of worker to remove details!" << endl;
                return true;
            }

        }
        else{
            if(Command::first_command == "help")   // no further functionality
                list_commands();
            else
                my_obj-> executeCommand(Command::first_command);
        }
    }
    else {
        cout << "Invalid command, Please use 'help' command to see the command manual " << endl;

    }

    return true;

}







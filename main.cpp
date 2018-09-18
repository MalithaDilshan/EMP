//main function of geting basic command from the user and pass to the command class



#include <iostream>
#include<string>

#include "command.h"
#include "worker.h"
#include "trainee.h"
#include "hashmap.h"
#include "employee.h"
#include "salariedemployee.h"
#include "hourlypaidemployee.h"
#include "datahandler.h"


using namespace std;


int main(){


    string command = " ";
    bool success = true;

    Command *com = new Command();
    cout << " " << endl;
    cout << "################################ Well Come to the Employee Management System ###############################" << endl;
    cout << " " << endl;

    while(success){
        success = false;
        cout << " " << endl;
        cout << "Please enter the command here: " ;
        // get the command from user
        getline(cin, command);
        // analyze and further execution
        success = com->run_command(command);

    }

    return 0;
}

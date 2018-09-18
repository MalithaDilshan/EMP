// Handleing data
#include "datahandler.h"


DataHandler::DataHandler(){
    // initialization the hashmap
    trainee_map_size = 25;
    employee_map_size = 100;
    trainee_data = new HashMap<Trainee*>(trainee_map_size);
    employee_data = new HashMap<Employee*>(employee_map_size);
    // load the initial data in the .txt file
    loadData();
}

DataHandler::~DataHandler(){
    delete trainee_data;
    delete employee_data;
}

// add new worker to the hashmap
void DataHandler::addWorker(char worker_type, char employee_type){

    if(worker_type == 'T'){
        Trainee* new_trainee = new Trainee();
        string name = " ";
        string id = " ";
        int age = 0;
        float allowance = 0;
        float duration = 0;

        while(1){
            cout << "Enter ID of the Trainee : " ;
            getline(cin, id);
            if(validate_key(id)){               // validation
                if((trainee_data->validateData(id)))
                    cout << "The key is already exist !, Please enter again." << endl;   
                else break;
            }
        }
        cout << "Enter name of the Trainee : " ;
        getline(cin, name);
        cout << "Enter age of the Trainee : ";
        cin >> age;
        cout << "Enter monthly allowance for the Trainee : " ;
        cin >> allowance;
        cout << "Enter duration the Training : " ;
        cin >> duration;
        cin.ignore(); // this will flush the newline of the 'cin' otherwise this will malfunction with the loop

        // set the values for the trainee object
        new_trainee->setID(id);
        new_trainee->setName(name);
        new_trainee->setAge(age);
        new_trainee->setAllowance(allowance);
        new_trainee->setDuration(duration);

        // insert the trainee object in the trainee hash map
        trainee_data->insertData(id, new_trainee);

    }

    else{
        string employee_id = " ";
        string name = " ";
        int age = 0;

        while(1){
            cout << "Enter Employee ID : " ;
            getline(cin, employee_id);
            if(validate_key(employee_id)){               // validation
                if((employee_data->validateData(employee_id)))
                    cout << "The key is already exist !, Please enter again." << endl;
                else break;
            }
        }
        cout << "Enter name of the employee : " ;
        getline(cin, name);
        cout << "Enter age : ";
        cin >> age ;
        cin.ignore();
        if(employee_type == 'S'){
            float salary;
            cout << "Enter monthly salary of the employee : ";
            cin >> salary;
            cin.ignore();
            // create  the objects with the down casting to the salaried employee
            //SalariedEmployee salaried_employee;
            Employee* emp = new SalariedEmployee();
            //emp = &salaried_employee;
            // put the data in to the object
            emp->setName(name);
            emp->setAge(age);
            emp->setID(employee_id);
            emp->setSalary(salary);
            // insert data to the hash map
            employee_data->insertData(employee_id, emp);
        }
        else{
            float rate;
            float hours;
            cout << "Enter hourly rate of the employee : ";
            cin >> rate;
            cout << "Enter number of hours: ";
            cin >> hours;
            cin.ignore();
            // create  the objects with the down casting to the salaried employee
            //HourlyPaidEmployee hourly_employee;
            Employee* emp = new HourlyPaidEmployee();
            //emp = &hourly_employee;
            // put the data in to the object
            emp->setName(name);
            emp->setAge(age);
            emp->setID(employee_id);
            emp->setHours(hours);
            emp->setRate(rate);
            // insert data to the hash map
            employee_data->insertData(employee_id, emp);
        }
    }

}
// get details of the worker according to the ID number
void DataHandler::getDetails(string id_number){


    if (trainee_data->isEmpty() && employee_data->isEmpty())
        cout << "The database is empty" << endl;

    if(validate_key(id_number)){

        if(trainee_data->validateData(id_number)){           // validation
            Trainee* trainee;
            trainee = trainee_data->displayData(id_number);
            cout << "* name of the trainee: " << trainee->getName() << endl;
            cout << "* age: " << trainee->getAge() << endl;
            cout << "* monthly allowance: " << trainee->getAllowance() << endl;
            cout << "* duration: " << trainee->getDuration() << endl;

        }
        else if(employee_data->validateData(id_number)){
            Employee* employee;
            employee = employee_data->displayData(id_number);

            //SalariedEmployee* sal_emp = (SalariedEmployee*) &employee;
            cout << "* name of the employee: " << employee->getName() << endl;
            cout << "* age: " << employee->getAge() << endl;
            cout << "* monthly salary: " << employee->getSalary() << endl;

        }
        else
            cout << "Entered ID number is not in the database" << endl;
    }


}
// remove a worker according to the ID number
void DataHandler::removeWorker(string id_number){
    bool success = false;
    if(validate_key(id_number)){       // validation
        if(id_number.at(0) == 'T'){
            success = trainee_data->deleteData(id_number);
        }
        else{
            success = employee_data->deleteData(id_number);
        }
        
        if(success)
            cout << "success!" << endl;
    }

}
// execute other commands
void DataHandler::executeCommand(string command){
    Trainee* t;
    Employee* e;
    int trainee_size, employee_size;

    trainee_size = trainee_data->getCount();
    employee_size = employee_data->getCount();
    if(command=="list_all"){
        for(int i=0; i<trainee_size; i++){
            t = trainee_data->getData(i);
            if(t != NULL){ 
                cout << "* ID number: " << t->getID() << endl;
                cout << "* name of the trainee: " << t->getName() << endl;
                cout << "* age: " << t->getAge() << endl;
                cout << "* monthly allowance: " << t->getAllowance() << endl;
                cout << "* duration: " << t->getDuration() << endl;
                cout << "---------------------------------------------------------" << endl;
            }
        }
        for(int i=0; i<employee_size; i++){
            e = employee_data->getData(i);
            if(e != NULL){
                cout << "* ID number: " << e->getID() << endl;
                cout << "* name of the employee: " << e->getName() << endl;
                cout << "* age: " << e->getAge() << endl;
                cout << "* monthly salary: " << e->getSalary() << endl;
                cout << "---------------------------------------------------------" << endl;
            }else{
                cout << "this is null"<<endl;    
            }
        }
    }
    // list the monthly payment for workers
    if(command == "list_monthly_pay"){
        for(int i=0; i<trainee_size; i++){
            t = trainee_data->getData(i);
            if(t != NULL){
                cout << "* ID number: " << t->getID() << endl;
                cout << "* monthly allowance: " << t->getAllowance() << endl;
                cout << "---------------------------------------------------------" << endl;
            }
        }
        for(int i=0; i<employee_size; i++){
            e = employee_data->getData(i);
            if(e != NULL){
                cout << "* ID number: " << e->getID() << endl;
                cout << "* monthly salary: " << e->getSalary() << endl;
                cout << "---------------------------------------------------------" << endl;
            }
            
        }
    }

    if(command == "get_total_pay"){

        // get the total of the all workers monthly
        float total = 0;
        float sub_total = 0;
        for(int i=0; i<trainee_size; i++){
                t = trainee_data->getData(i);
                if(t != NULL)
                    total = total + t->getAllowance();
        }
        
        sub_total = total;
        for(int i=0; i<employee_size; i++){
                e = employee_data->getData(i);
                if(e != NULL)
                    total = total + e->getSalary();            
        }

        cout << "monthly total payment for the trainees: " << sub_total << endl;
        cout << "monthly total pay for the emplyees    : " << total - sub_total << endl;
        cout << "monthly total payment for workers is  : " << total << endl;

    }

}

// this will load the existing hashmap via reading the .txt file
void DataHandler:: loadData(){
    string array[5];
    string line;
    int i = 0;

    ifstream file("EmployNTraineeInfo.txt"); // opening the file

    if (file.is_open()){
        // read untile the end of the file
        while(! file.eof()){
            getline(file, line); // get a line from the file
            //array[i] = line;
            
            stringstream ss(line);
            string word;
            int count=0;  // track the employee type
            // seperate the string by comma
            while(getline(ss,word, ',')){
                array[count] = word;
                count++;
            }

            if((count == 5) && (array[0][0]== 'T')){
                Trainee* trainee1 = new Trainee();
                if(validate_key(array[0])){         // validation
                    trainee1->setID(array[0]);
                    trainee1->setName(array[1]);
                    trainee1->setAge(stoi(array[2]));
                    trainee1->setAllowance(strtof((array[3]).c_str(),0));
                    trainee1->setDuration(strtof((array[4]).c_str(),0));
                    // put data into the hashmap
                    trainee_data->insertData(array[0], trainee1);
                }

            }
            
            if((count == 5) && (array[0][0]== 'E')){
                Employee* employee1 = new HourlyPaidEmployee();
                if(validate_key(array[0])){         // validation
                    employee1->setID(array[0]);
                    employee1->setName(array[1]);
                    employee1->setAge(stoi(array[2]));
                    employee1->setHours(strtof((array[3]).c_str(),0));
                    employee1->setRate(strtof((array[4]).c_str(),0));
                    // put data into the hashmap
                    employee_data->insertData(array[0], employee1);
                }

            }

            if((count == 4) && (array[0][0]== 'E')){
                Employee* employee1 = new SalariedEmployee();
                if(validate_key(array[0])){         // validation
                    employee1->setID(array[0]);
                    employee1->setName(array[1]);
                    employee1->setAge(stoi(array[2]));
                    employee1->setSalary(strtof((array[3]).c_str(),0));
                    // put data into the hashmap
                    employee_data->insertData(array[0], employee1);
                }

            }            

            i++;
        }
        file.close(); // close the file
    }

    else cout << "can not open the file" << endl;


}

// validate the ID that enter to the database
bool DataHandler:: validate_key(string key){
    bool success = false;
    int length = 0;
    int number;
    // validation for the trainee
    if((key[0] == 'T') && (key[1] == 'R')){
        length = key.length();
        char arr[length-2];
        for(int i=0; i<length-2; i++){
            arr[i] = key[i+2];
        }
        number = stoi((string)arr);
        if(number >= trainee_map_size) cout << "limit exceeded!" << endl;
        else success = true;
    }
    // validation for the employee
     if((key[0] == 'E') && (key[1] == 'M')){
        length = key.length();
        char arr[length-2];
        for(int i=0; i<length-2; i++){
            arr[i] = key[i+2];
        }
        number = stoi((string)arr);
        if(number >= employee_map_size) cout << "limit exceeded!" << endl;
        else success = true;
    }

    if(!success)
        cout << "please enter valid ID for the worker" << endl;



    return success;

}


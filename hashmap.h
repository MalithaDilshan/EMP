#ifndef HASHMAP_H
#define HASHMAP_H

#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<iterator>


using namespace std;

template <class T>
class HashMap{

private:
    vector<T> my_data;  // store data using use specified size vector
    list<string> my_list;

    int vector_size;
    int number_of_item;

public:
    // constructor
    HashMap(int x):my_data(x){
        vector_size = x;
        number_of_item = 0;  // initialize the count
    }

    // prototypes
    int getHash(string key);
    void insertData(string key1, T *value1);
    void insertData(string key1, T value1);
    void displayAllKeys();
    void displayAllData();
    T displayData(string key);
    bool validateData(string key);
    bool deleteData(string key);
    int getCount();
    bool isEmpty();
    T getData(int index);


};

// get the hash code of a string
template <class T>
int HashMap<T>::getHash(string key){
    int hash_code = 1;
    int mod = vector_size;  // mode with the vectored size
    int shift = 19;

    for(unsigned int i=0;i<key.length();i++){
        hash_code = ((shift*hash_code)%mod+ key[i])%mod;  // get the hash code using this
    }

    return hash_code;

}

// insert key value pair into the hash map
template <class T>
void HashMap<T>:: insertData(string key1, T *value1){
    list<string>::iterator it;
    bool exist = false;
    for(list<string>::const_iterator i = my_list.begin(); i != my_list.end(); ++i){
        string exist_key = string(i->c_str());
        if(key1 == exist_key){
            exist = true;
            cout << key1 << ", ID is already exist !!" << endl;
            break;
        }
    }
    if(!exist){
        int code = getHash(key1);
        my_data.at(code) = value1;  // put the object in the hash index
        my_list.push_back(key1);
        number_of_item ++ ;  // increase the count according to the updating

    }
}

// insert key value pair into the hash map
template <class T>
void HashMap<T>:: insertData(string key1, T value1){
    list<string>::iterator it;
    bool exist = false;
    for(list<string>::const_iterator i = my_list.begin(); i != my_list.end(); ++i){
        string exist_key = string(i->c_str());
        if(key1 == exist_key){
            exist = true;
            cout << key1 << ", ID is already exist !!" << endl;
            break;
        }
    }
    if(!exist){
        int code = getHash(key1);
        my_data.at(code) = value1;  // put the object in the hash index
        my_list.push_back(key1);
        number_of_item ++ ;  // increase the count according to the updating

    }
}

// delete a specified data according to the given key
template <class T>
bool HashMap<T>:: deleteData(string key){
    int code;
    bool success = false;

    if(validateData(key)){
        code = getHash(key);
        my_list.remove(key); // remove the key from the list
        //my_data.erace(my_data.begin()+(code));  // delete a one element in the vector
        // delete the reference of the code
        delete my_data.at(code);
        number_of_item --;
        success = true;
    }
    else cout << "the ID is not found!";
    return success;

}

// display all the keys for already exist data in the hash map
template <class T>
void HashMap<T>:: displayAllKeys(){
    list<string>::iterator it;
    for(list<string>::const_iterator i = my_list.begin(); i != my_list.end(); ++i){
        cout << i->c_str() << endl;
    }
}

// display all data that already exist
template <class T>
void HashMap<T>:: displayAllData(){
    int code;
    list<string>::iterator it;
    if(!isEmpty()){
        for(list<string>::const_iterator i = my_list.begin(); i != my_list.end(); ++i){
            string key_value = (string)i->c_str();
            code = getHash(key_value);
        }
    }
    else
        cout << "The list is empty" << endl;

}

// display data for specified key
template <class T>
T HashMap<T>:: displayData(string key){
    int code;
    code = getHash(key);

    return my_data.at(code);
}

// validate the user input key
template <class T>
bool HashMap<T>::validateData(string key){
    bool check = false;
    for(list<string>::const_iterator i = my_list.begin(); i != my_list.end(); ++i){
        if(i->c_str() == key)
            check = true;
    }

    return check;

}

// get the count of the filled data
template <class T>
int HashMap<T>::getCount(){
    return number_of_item;

}

// check whether the hash map is empty or not
template <class T>
bool HashMap<T>::isEmpty(){
    bool empty_x = false;
    if(number_of_item ==0){empty_x = true;}

    return empty_x;

}

template <class T>
// get data stored in hash map according to the given index.
T HashMap<T>::getData(int index){
    int code = 0;
    list<string>::iterator it = my_list.begin();
    advance (it,index);
    string key = *it;
    if(validateData(key)){
        code = getHash(key);
    }

    return my_data.at(code);
}


#endif // HASHMAP_H

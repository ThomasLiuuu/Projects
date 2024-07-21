#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
using namespace std;

// exception class, deal with any error occuring
class error : public exception{
private: 
    // private variable err, store the error message
    char* err;
public:
    // return user the error message, tell the user what error has occured
    char* get_err()
    {
        return this->err;
    }
    // receive the error message, and assign it to the private varibale err
    error(char* err)
    {
        this->err = err;
    }
};

class CondoDatabase{
// private variable
private:
    // store name
    vector <string> name;
    // store floor
    vector <int> floor;
    // store unit number
    vector <int> uniNum;
    // store phone number
    vector <string> phoNum;
// public function
public:
    // show user the menu of the program, and the options they have
    void menu();
    // Add records function
    void addRecord(string name, int floor, int uniNum, string phoNum);
    // List records function
    void listRecord();
    // Modify records function
    void modifyRecord(int floor, int uniNum);
    // Delete records function
    void deleteRecord(string name);
    // Exit program function
    bool exitProgram();
    // clear all vector, resize to 0
    bool clean();
    // show user what step he is in
    virtual void header();
    // length of vector
    bool length();
};

// show user the menu of the program, and the options they have
void CondoDatabase::menu()
{
    cout << "---- CONDO DATABASE MENU ----" << endl;
    cout << "   1. Add records" << endl;
    cout << "   2. List records" << endl;
    cout << "   3. Modify records" << endl;
    cout << "   4. Delete records" << endl;
    cout << "   5. Check menu" << endl;
    cout << "   6. Exit program" << endl;
}

// Add records function
void CondoDatabase::addRecord(string name, int floor, int uniNum, string phoNum)
{
    // store information into vector
    this->name.push_back(name);
    this->floor.push_back(floor);
    this->uniNum.push_back(uniNum);
    this->phoNum.push_back(phoNum);
    // tell user information has been stored
    cout << "Information has been stored." << endl;
}

// List records function
void CondoDatabase::listRecord()
{
    // determine the length of the vector, find how many users are stored in the vector
    int length = this->name.size();
    // if there is information stored
    if (length > 0)
    {
        // use for loop to list all the informations
        for (int i = 0; i < length; i++)
        {
            cout << "User name: " << this->name[i] << endl;
            cout << "Floor: " << this->floor[i] << endl;
            cout << "Unit number: " << this->uniNum[i] << endl;
            cout << "Phone number: " << this->phoNum[i] << endl;
            cout << endl;
        }
    }
    // if no information has been stored yet
    else
    {
        // throw error message
        throw error("No information has been stored yet.");
    }
}

// Modify records function
void CondoDatabase::modifyRecord(int floor, int uniNum)
{
    string name;
    // determine the length of the vector, find how many users are stored in the vector
    int length = this->name.size();
    // if the floor and unit number has been stored in the vector
    if (find(this->floor.begin(), this->floor.end(), floor) != this->floor.end() && find(this->uniNum.begin(), this->uniNum.end(), uniNum) != this->uniNum.end())
    {
        // use for loop to check which user's information is going to be modified
        for (int i = 0; i < length; i++)
        {
            // find the user that will be modified
            if (this->floor[i] == floor)
            {
                if (this->uniNum[i] == uniNum)
                {
                    // flush input buffer
                    cin.sync();
                    // modify the information
                    cout << "Enter new user name: ";
                    getline(cin, name); 
                    this->name.at(i) = name;
                    cout << "Enter new phone number: ";
                    cin >> this->phoNum.at(i);
                    cout << "Information has been modified. " << endl;
                }
            }
        }
    }
    else
    {
        // if there is no information about this floor and unitnumber
        throw error("There is no one live in this room. ");
    }
}

// Delete records function
void CondoDatabase::deleteRecord(string name)
{
    // determine the length of the vector, find how many users are stored in the vector
    int length = this->name.size();
    // if the user has been stored in the vector
    if (find(this->name.begin(), this->name.end(), name) != this->name.end())
    {
        // use for loop to check which user's information is going to be deleted
        for (int i = 0; i < length; i++)
        {
            // find the user that will be deleted
            if (this->name[i] == name)
            {
                // erase all the information
                this->name.erase(this->name.begin()+i);
                this->floor.erase(this->floor.begin()+i);
                this->uniNum.erase(this->uniNum.begin()+i);
                this->phoNum.erase(this->phoNum.begin()+i);
                cout << "User deleted" << endl;
            }
        }
    }
    else 
    {
        // if the user to be deleted is not stored
        throw error("The user to be deleted does not exist.");
    }
}

// Exit program function
bool CondoDatabase::exitProgram()
{
    cout << "Thank you for using the program." << endl;
    return false;
}

// clear all vector, resize to 0
bool CondoDatabase::clean()
{
    // clear all vector
    this->name.clear();
    this->floor.clear();
    this->uniNum.clear();
    this->phoNum.clear();
}

// show user what step he is in
void CondoDatabase::header()
{
    // default output
    cout << "-------Welcome to---------------------------------------------------" << endl;
    cout << "=====|  =====  ==    == ====     ===== "<< endl;
    cout << "||     ||   || ||\\\\  || ||  \\\\  ||   ||"<< endl;
    cout << "||     ||   || || \\\\ || ||   || ||   ||"<< endl;
    cout << "||     ||   || ||  \\\\|| ||  //  ||   ||"<< endl;
    cout << "=====|  =====  ==    == ====     ===== "<< endl;
    cout << "====       ==    =======    ==     ====\\\\      ==       ===   =====|" << endl;
    cout << "||  \\\\    //\\\\     |||     //\\\\    ||   ||    //\\\\    //   \\\\ ||    " << endl;
    cout << "||   ||  //  \\\\    |||    //  \\\\   ||==<<    //  \\\\   \\\\===\\\\ ||===|" << endl;
    cout << "||  //  //----\\\\   |||   //----\\\\  ||   ||  //----\\\\  \\\\   // ||    " << endl;
    cout << "====   ==      ==  |||  ==      == ====//  ==      ==   ===   =====|" << endl;
    cout << "--------------------------------------------------------------------" << endl;
}

// for add record function
class add : public CondoDatabase
{
    void header()
    {
        cout << "*************************" << endl;
        cout << "Add Records:" << endl; 
        cout << "*************************" << endl;
    }
};

// for list record function
class list : public CondoDatabase
{
    void header()
    {
        cout << "*************************" << endl;
        cout << "List Records:" << endl; 
        cout << "*************************" << endl;
    }
};

// for modify record function
class modify : public CondoDatabase
{
    void header()
    {
        cout << "*************************" << endl;
        cout << "Modify Records:" << endl; 
        cout << "*************************" << endl;
    }
};

// for delete record function
class delet : public CondoDatabase
{
    void header()
    {
        cout << "*************************" << endl;
        cout << "Delete Records:" << endl; 
        cout << "*************************" << endl;
    }
};

// length of vector
bool CondoDatabase::length()
{
    return this->name.size();
}

// main function, process all the information
int main()
{
    // set a variable to call all functions under class CondoDatabase 
    CondoDatabase condo;
    // call header variable and pointer
    add ad;
    CondoDatabase* AD = &ad;
    list li;
    CondoDatabase* LI = &li;
    modify mo;
    CondoDatabase* MO = &mo;
    delet de;
    CondoDatabase* DE = &de;
    // header
    condo.header();
    // show menu of the program
    condo.menu();
    
    bool run = true;
    int command;
    // variables to get user input
    string name;
    int floor;
    int uniNum;
    string phoNum;
    int length;
    // use boolean while loop to ask user for different functions they want to use
    while (run)
    {
        // ask user for which function they want to use
        cout << "Enter the command number: ";
        cin >> command;

        // test if the user is inputing 1-6 to call function
        try
        {
            // if user didn't input integer value to run program
            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                cin.sync();
                throw error("Please enter integer 1-6 to run the program.");
            }
            else
            {
                switch (command){
                    // add new record when input 1
                    case 1:
                        // flush input buffer
                        cin.sync();
                        // header 
                        AD->header();
                        // ask user to input information
                        cout << "Enter name: ";
                        getline(cin, name);
                        cout << "Enter floor: ";
                        cin >> floor;
                        cout << "Enter unit number: ";
                        cin >> uniNum;
                        cout << "Enter phone number: ";
                        cin >> phoNum;
                        condo.addRecord(name, floor, uniNum, phoNum);
                        break;
                    // list record when input 2
                    case 2:
                        // header 
                        LI->header();
                        condo.listRecord();
                        break;
                    // modify record when input 3
                    case 3:
                        // header 
                        MO->header();
                        // if there is no information been stored
                        length = condo.length();
                        if (length == 0)
                        {
                            throw error("No user information has been stored.");
                        }
                        else
                        {
                            // ask user for which user should be modified
                            cout << "Enter the floor: ";
                            cin >> floor;
                            cout << "Enter the unit number: ";
                            cin >> uniNum;
                            condo.modifyRecord(floor, uniNum);
                        }
                        break;
                    // delete record when input 4
                    case 4:
                        // flush input buffer
                        cin.sync();
                        // header 
                        DE->header();
                        // if there is no information been stored
                        length = condo.length();
                        if (length == 0)
                        {
                            throw error("No user information has been stored.");
                        }
                        else
                        {
                            // ask user for which user should be deletedd
                            cout << "Enter the user name to delete: ";
                            getline(cin, name);
                            condo.deleteRecord(name);
                        }
                        break;
                    // show menu when input 5
                    case 5:
                        condo.menu();
                        break;
                    // exit program when input 6
                    case 6:
                        run = condo.exitProgram();
                        break;
                    // if user didn't number 1-6
                    default:
                        throw error("Please enter number 1-6 to continue running the program.");
                }
            }
        }
        // catch error command input
        catch(error &except)
        {
            cout << except.get_err() << endl;
        }
    }

    // clear all information
    condo.clean();

    return 0;
}
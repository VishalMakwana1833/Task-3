/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Record {
    string name;
    string phone;
};

vector<Record> phoneBook;

void loadPhoneBook() {
    ifstream file("phonebook.txt");
    if (file.is_open()) {
        string name, phone;
        while (file >> name >> phone) {
            Record record = {name, phone};
            phoneBook.push_back(record);
        }
        file.close();
    }
}

void savePhoneBook() {
    ofstream file("phonebook.txt");
    if (file.is_open()) {
        for (Record record : phoneBook) {
            file << record.name << " " << record.phone << endl;
        }
        file.close();
    }
}

void addRecord() {
    string name, phone;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter phone: ";
    getline(cin, phone);
    Record record = {name, phone};
    phoneBook.push_back(record);
    savePhoneBook();
}

void listRecords() {
    for (Record record : phoneBook) {
        cout << record.name << " " << record.phone << endl;
    }
}

int main() {
    loadPhoneBook();
    while (true) {
        cout << "Phone Book Menu:" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. List Records" << endl;
        cout << "3. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                listRecords();
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
    return 0;
}








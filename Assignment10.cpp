// Name: Arwa Salujiwala	Roll no: 23555	Batch: S3  

// DSA Assignment 10

//Department maintains student’s database. The file contains roll number, name, division and address. 
//Write a program to create a sequential file to store and maintain student data. It should allow the user 
//to add, delete information of student. Display information of particular student. If record of student 
//does not exist an appropriate message is displayed. If student record is found it should display the 
//student details.

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Student {
    int rollNo;
    char name[50];
    char division;
    char address[100];
};

// Function to add a new student record
void addStudent() {
    ofstream file("students.txt", ios::app);  // Open file in append mode
    
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student student;
    cout << "Enter roll number: ";
    cin >> student.rollNo;
    cin.ignore();  // To consume the newline left in the buffer

    cout << "Enter name: ";
    cin.getline(student.name, 50);

    cout << "Enter division: ";
    cin >> student.division;
    cin.ignore();

    cout << "Enter address: ";
    cin.getline(student.address, 100);

    file.write(reinterpret_cast<char*>(&student), sizeof(student));
    file.close();
    cout << "Student record added successfully!" << endl;
}

// Function to display student information based on roll number
void displayStudent() {
    ifstream file("students.txt", ios::in);  // Open file in read mode
    
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    int rollNo;
    cout << "Enter roll number to display: ";
    cin >> rollNo;

    Student student;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        if (student.rollNo == rollNo) {
            found = true;
            cout << "\nStudent Information:\n";
            cout << "Roll Number: " << student.rollNo << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            break;
        }
    }

    if (!found) {
        cout << "Student record not found!" << endl;
    }

    file.close();
}

// Function to delete a student record
void deleteStudent() {
    ifstream file("students.txt", ios::in);  // Open file in read mode
    ofstream tempFile("temp.txt", ios::out);  // Temporary file to store the new records
    
    if (!file || !tempFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    int rollNo;
    cout << "Enter roll number to delete: ";
    cin >> rollNo;

    Student student;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        if (student.rollNo == rollNo) {
            found = true;
            cout << "Student record with roll number " << rollNo << " has been deleted." << endl;
        } else {
            tempFile.write(reinterpret_cast<char*>(&student), sizeof(student));
        }
    }

    if (!found) {
        cout << "Student record not found!" << endl;
    }

    file.close();
    tempFile.close();

    // Remove original file and rename temporary file to original file name
    if (remove("students.txt") != 0) {
        cout << "Error deleting file!" << endl;
    } else if (rename("temp.txt", "students.txt") != 0) {
        cout << "Error renaming file!" << endl;
    }
}

// Function to display menu options and process user choice
void menu() {
    int choice;

    do {
        cout << "\nStudent Database Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Display Student Information\n";
        cout << "3. Delete Student Record\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudent();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
}

int main() {
    menu();  // Start the menu-driven program
    return 0;
}

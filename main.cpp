#include <iostream>
#include "cart.h"  
#include "managerint.h"
#include "interface.h"
#include "customerint.h"
#include "department.h"
#include "product.h"
//include all the file

using namespace std;

int deptcount = 0;  //global variable

extern Department* StoreDepartments;  

// Menu function to choose which interface to use
int menu() {
    int choice;
    bool done = false;
    while (!done) {
        cout << "Customer [1]\nManager [2]\nExit [3]\n";
        cout << "Enter your choice [1, 2, 3]: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Customer" << endl;
            return 1;
        }
        else if (choice == 2) {
            cout << " Manager" << endl;
            return 2;
        }
        else if (choice == 3) {
            cout << "exit!\n";
            return 3;
        }
        else {
            cout << "enter 1,2,3 or 3" << endl;
        }
    }
    return 0;  
}

// Function to handle the Manager interface
void manager_int() {
    Managerint* interface = new Managerint();

    int choice;
    bool done = false;
    while (!done) {
        cout << "\nManager Main Menu\n";
        cout << "1. List Departments\n";
        cout << "2. Add Department\n";
        cout << "3. Add Item to Department\n";
        cout << "4. save changes\n";
        cout << "5. Exit\n";
        cout << "Enter your choice [1, 2, 3, 4, 5]: ";
        cin >> choice;

        if (choice == 1) {
            interface->listdep();
        }
        else if (choice == 2) {
            interface->addDep();
        }
        else if (choice == 3) {
            interface->addItemToDepartment();
        }
        else if (choice == 4) {
            interface->saveChangesToCSV();
        }
        else if (choice == 5) {
            done = true;  // exit theinterface
        }
        else {
            cout << "Invalid choice. Please try again.\n"; // error
        }
    }

    delete interface;  // freeing the memeory
}

// customer interface
void customer_int() {
    Customerint* interface = new Customerint();

    int choice;
    bool done = false;
    while (!done) {// optiond for the interface
        cout << "\nCustomer Main Menu\n";
        cout << "1. Show Cart\n";
        cout << "2. Browse Departments\n";
        cout << "3. Exit\n";
        cout << "Enter your choice [1, 2, 3]: ";
        cin >> choice;

        if (choice == 1) {
            interface->showCartMenu();
        }
        else if (choice == 2) {
            interface->browseDepartments();
        }
        else if (choice == 3) {
            done = true;  // Exit the customer interface
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    delete interface;  // Cleanup
}

int main() {
    loadDataFromCsv("C:\\Users\\SNAKS\\source\\repos\\Elijah\\labs\\Grocerysystem\\grocery.csv"); //csv file location
    // menu for the user to select Customer, Manager, or Exit
    int choice = menu();

    if (choice == 1) {
        customer_int();  // customer interface
    }
    else if (choice == 2) {
        manager_int();  // manager interface
    }
    else {
        cout << "Exiting program.\n";  // Exit
    }

    return 0;
}

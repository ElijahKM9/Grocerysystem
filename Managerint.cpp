#include "interface.h" 
#include "managerint.h" 
#include "department.h"   
#include "product.h"  
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

extern Department* StoreDepartments;
extern int TotalDepartments = 0;

Department* StoreDepartments = nullptr;
Managerint::Managerint() {}

void Managerint::mainmenu() {
    cout << "Manager Menu:" << endl;
    cout << "1. List Departments" << endl;
    cout << "2. Add Department" << endl;
    cout << "3. Add Item to Department" << endl;
    cout << "4. Save Changes to file" << endl;
    cout << "5. Exit" << endl;
    cout << "choice: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        listdep();
    }
    else if (choice == 2) {
        addDep();
    }
    else if (choice == 3) {
        addItemToDepartment();
    }
    else if (choice == 4) {
        saveChangesToCSV();
    }
    else if (choice == 5) {
        cout << "Exiting" << endl;
    }
    else {
        cout << "Choose 1, 2, 3, 4, or 5" << endl;
    }
}

void Managerint::listdep() {
    if (TotalDepartments == 0) {
        cout << "No departments" << endl;
        return;
    }

    for (int i = 0; i < TotalDepartments; ++i) {
        cout << i + 1 << ". " << StoreDepartments[i].getName() << endl;
        StoreDepartments[i].listItems();
    }
}

void Managerint::addDep() {
    char departmentName[50];
    cout << "Enter department name: ";
    cin.ignore();
    cin.getline(departmentName, sizeof(departmentName));

    if (strlen(departmentName) == 0) { // if they enter an empyty string 
        cout << "empty name"<< endl;
        return;
    }

    Department newDept(departmentName);
    Department* newStoreDepartments = new Department[TotalDepartments + 1];

    for (int i = 0; i < TotalDepartments; ++i)
        newStoreDepartments[i] = StoreDepartments[i];

    newStoreDepartments[TotalDepartments] = newDept;

    delete[] StoreDepartments;
    StoreDepartments = newStoreDepartments;
    TotalDepartments++;

    cout << "department added"<< endl;
}

void Managerint::addItemToDepartment() {
    if (TotalDepartments == 0) {
        cout << "No departments available."<< endl;
        return;
    }

    listdep();
    int deptChoice;
    cout << "Enter department number [0 to go back]: ";
    cin >> deptChoice;

    if (deptChoice == 0) return;
    if (deptChoice < 1 || deptChoice > TotalDepartments) { //error they pick a number the either to low or to high 
        cout << "Invalid department number!"<< endl;
        return;
    }

    Department& selectedDept = StoreDepartments[deptChoice - 1];

    char itemName[50];
    float itemPrice;
    int itemQuantity;

    cout << "Enter item name: ";
    cin.ignore();
    cin.getline(itemName, sizeof(itemName));

    if (strlen(itemName) == 0) {
        cout << "Item name cannot be empty!"<< endl;
        return;
    }

    cout << "Enter item price: ";
    cin >> itemPrice;
    if (itemPrice <= 0) {
        cout << "Invalid price" << endl;
        return;
    }

    cout << "Enter item quantity: ";
    cin >> itemQuantity;
    if (itemQuantity <= 0) {
        cout << "Invalid quantity. Must be positive."<< endl;
        return;
    }

    Product newProduct(itemName, itemPrice, itemQuantity);
    selectedDept.addItem(newProduct);

    cout << "Item added successfully."<< endl;
}

void Managerint::saveChangesToCSV() {
    // Open the file 
    ofstream file("C:\\Users\\SNAKS\\source\\repos\\Elijah\\labs\\Grocerysystem\\grocery.csv");

  
    if (!file.is_open()) {
        cout << "couldnt open file"<< endl;
        return;
    }

    // total number of departments sent
    file << TotalDepartments << endl;

    // run through each dept
    for (int i = 0; i < TotalDepartments; ++i) {
        Department& dept = StoreDepartments[i]; // derefernecing the object at that position in the array

        // write the department name and number of items in the department
        file << dept.getName() << ", " << dept.getTotalItems() << endl;

        // run through each product
        for (int j = 0; j < dept.getTotalItems(); ++j) {
            Product* product = dept.getItem(j);

            //writes its values
            file << product->pullname() << ", "
                << product->pullprice() << ", "
                << product->pullquanity() << ""<< endl;
        }
    }

    // Closes the file
    file.close();
    // tells user it was done succesfully
    cout << "Changes saved successfully to CSV."<< endl;
}


// Function to load data from the CSV file
int loadDataFromCsv(const char* filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    string line;
    getline(file, line); 
    TotalDepartments = stoi(line);

    StoreDepartments = new Department[TotalDepartments]; 

    for (int d = 0; d < TotalDepartments; d++) {
        getline(file, line);
        string depName;
        int pCount;

        stringstream ss(line);
        getline(ss, depName, ',');  
        ss >> pCount; 

        Product* P = new Product[pCount]; 

        
        for (int i = 0; i < pCount; i++) {
            getline(file, line);
            string pName;
            float pPrice;
            int pQuantity;

            stringstream ss(line);
            getline(ss, pName, ',');  
            ss >> pPrice;  
            ss.ignore();    
            ss >> pQuantity;  

            P[i].set(pName.c_str(), pPrice, pQuantity);  
        }

        // Set the department info
        StoreDepartments[d].setDepartmentInfo(depName.c_str(), P, pCount);
    }

    file.close();  // Close the file after reading

    return 0;  // Return success
}

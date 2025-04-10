#include "Department.h"
#include <iostream>
#include <cstring>

using namespace std;

Department::Department() {
    strcpy_s(name, "");
    items = nullptr;
    totalItems = 0;
}

Department::Department(const char* deptName) {
    setName(deptName);
    items = nullptr;
    totalItems = 0;
}

Department::~Department() {
    delete[] items;
}

void Department::setName(const char* deptName) {
    strcpy_s(name, deptName);
}

const char* Department::getName() const {
    return name;
}

void Department::addItem(const Product& product) {
    Product* temp = new Product[totalItems + 1]; // creates the new array for the product
    for (int i = 0; i < totalItems; ++i) { //copies all the current items into the new array cause just made the bigger one
        temp[i] = items[i];
    }
    temp[totalItems] = product; // adds the new product

    delete[] items; // clear the memory
    items = temp; // replaces it 
    totalItems++;
}

void Department::listItems() const {
    for (int i = 0; i < totalItems; ++i) {
        cout << i + 1 << ". ";
        items[i].showproduct();
    }
}

Product* Department::getItem(int index) {
    if (index >= 0 && index < totalItems) {
        return &items[index];
    }
    return nullptr;
}

int Department::getTotalItems() const {
    return totalItems;
}

void Department::setDepartmentInfo(const char* deptName, Product* prodArray, int count) {
    setName(deptName); // Set the department name using setName

    // Allocate memory for items array
    items = new Product[count];
    totalItems = count;

    // Copy the products into the department
    for (int i = 0; i < count; ++i) {
        items[i] = prodArray[i];  // Assuming Product has a proper copy constructor
    }
}
#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Product.h"

class Department {
private:
    char name[100];
    Product* items;
    int totalItems;

public:
    Department();
    Department(const char* deptName);
    ~Department();

    void setName(const char* deptName);
    const char* getName() const;
    void addItem(const Product& product);
    void listItems() const;
    Product* getItem(int index);
    int getTotalItems() const;
    void setDepartmentInfo(const char* name, Product* prodArray, int count);
};

#endif

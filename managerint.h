#pragma once
#ifndef MANAGERINT_H
#define MANAGERINT_H

#include "interface.h"


int loadDataFromCsv(const char* filePath);


class Managerint : public Interface {
public:
    Managerint();
    void showCartMenu() override {} // Not used for manager
    void browseDepartments() override {} // Not used for manager

    void mainmenu();
    void listdep();
    void addDep();
    void addItemToDepartment();
    void saveChangesToCSV(); 
    
};

#endif

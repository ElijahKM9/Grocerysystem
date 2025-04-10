#include "department.h"
#include "product.h"
#include "customerint.h"
#include "cart.h"
#include <iostream>
#include <cstring>
using namespace std;

extern Department* StoreDepartments;
extern int deptcount;


Customerint::Customerint() {}

void Customerint::showCartMenu() {
    int choice;
    bool done = false;
    while (!done) {
        cout << "\nCart Menu\n";
        cout << "1. List Items\n";
        cout << "2. Checkout\n";
        cout << "3. Return to Main Menu\n";
        cout << "Enter your choice [1, 2, 3]: ";
        cin >> choice;

        if (choice == 1) {
            listItemsInCart();
        }
        else if (choice == 2) {
            checkoutCart();
        }
        else if (choice == 3) {
            done = true;  // Exit the loop and return to the main menu
        }
        else {
            cout << "Invalid input. Try again.\n";
        }
    }
}



void Customerint::browseDepartments() {
    while (true) {
        if (deptcount == 0) {
            cout << "No departments available.\n";
            return;
        }

        cout << "\nAvailable Departments:\n";
        for (int i = 0; i < deptcount; i++) { // runs through the list of availibe department 
            cout << i + 1 << ". " << StoreDepartments[i].getName() << "\n";
        }

        int choice;
        cout << "Options:\n1. List Items of a Department\n2. Go Back to Main Menu\n";
        cout << "Enter your choice [1, 2]: ";
        cin >> choice;

        if (choice == 1) {
            int deptNum;
            cout << "Enter department number [0 to go back]: ";
            cin >> deptNum;

            if (deptNum == 0) 
                continue;
            if (deptNum < 1 || deptNum > deptcount) {
                cout << "Invalid department number.\n";
                continue;
            }

            listItemsInDepartment(deptNum - 1);

        }
        else if (choice == 2) {
            return;
        }
        else {
            cout << "Invalid input. Try again.\n";
        }
    }
}

void Customerint::listItemsInCart() {
    cart.listCartItems();
}

void Customerint::checkoutCart() {
    if (cart.isEmpty()) {
        cout << "No items in the cart.\n";
    }
    else {
        cart.checkout();
        cout << "Thank you for your purchase.\n";
    }
}

void Customerint::listItemsInDepartment(int deptIndex) {
    Department& dept = StoreDepartments[deptIndex];

    cout << "\nItems in Department: " << dept.getName() << "\n";
    dept.listItems();

    int choice;
    cout << "Options:\n1. Add to Cart an Item\n2. Go Back to Browse Departments Menu\n";
    cout << "Enter your choice [1, 2]: ";
    cin >> choice;

    if (choice == 1) {
        int itemIndex;
        cout << "Enter item number to buy [0 to go back]: ";
        cin >> itemIndex;

        if (itemIndex == 0)
            return;
        if (itemIndex < 1 || itemIndex > dept.getTotalItems()) { //error handling
            cout << "Invalid item number.\n";
            return;
        }

        int quantity;
        cout << "Enter quantity: ";
        cin >> quantity;
        if (quantity <= 0) {
            cout << "Quantity must be a positive integer.\n";
            return;
        }

        Product item = *StoreDepartments[deptIndex].getItem(itemIndex);
        cart.addToCart(item, quantity);
        cout << "Item added to cart.\n";
    }
}



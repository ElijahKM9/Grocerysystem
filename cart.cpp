#include "Cart.h"
#include <iostream>
#include <cstring>

using namespace std;

Cart::Cart() {
    items = nullptr;
    quantities = nullptr;
    totalItems = 0;
    totalCost = 0;
}

Cart::~Cart() {
    delete[] items;
    delete[] quantities;
}

void Cart::addToCart(const Product& product, int quantity) {
    Product* tempItems = new Product[totalItems + 1];
    int* tempQty = new int[totalItems + 1];

    for (int i = 0; i < totalItems; ++i) {
        tempItems[i] = items[i];
        tempQty[i] = quantities[i];
    }

    tempItems[totalItems] = product;
    tempQty[totalItems] = quantity;

    delete[] items;
    delete[] quantities;

    items = tempItems;
    quantities = tempQty;

    totalItems++;
    totalCost += product.pullprice() * quantity * 1.13f; // 13% tax
    cout << "Item added to cart.\n";
}

void Cart::listCartItems() const {
    if (totalItems == 0) {
        cout << "Cart is empty.\n";
        return;
    }

    for (int i = 0; i < totalItems; ++i) {
        cout << i + 1 << ". " << items[i].pullname()
            << " - $" << items[i].pullprice()
            << " x " << quantities[i] << endl;
    }
    cout << "Total with tax: $" << totalCost << endl;
}

void Cart::checkout() {
    if (totalItems == 0) {
        cout << "No items in the cart.\n";
        return;
    }
    cout << "Thank you for your purchase!\n";
    delete[] items;
    delete[] quantities;
    items = nullptr;
    quantities = nullptr;
    totalItems = 0;
    totalCost = 0;
}

bool Cart::isEmpty() const {
    return totalItems == 0;
}

int Cart::cartsize()
{
    return totalItems;
}
#ifndef CART_H
#define CART_H

#include "Product.h"

class Cart {
private:
    Product* items;
    int* quantities;
    int totalItems;
    float totalCost;

public:
    Cart();
    ~Cart();
    void addToCart(const Product& product, int quantity);
    void listCartItems() const;
    void checkout();
    bool isEmpty() const;
    int cartsize();
};

#endif


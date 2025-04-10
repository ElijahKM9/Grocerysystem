#include "Product.h"
#include <iostream>
#include <cstring>

using namespace std;

Product::Product() {
    strcpy_s(name, "");
    price = 0.0f;
    quanity = 0;
}

void Product::set(const char* n, float p, int q)
{
    strcpy_s(name, n);
    price = p;
    quanity = q;
}
Product::Product(const char* n, float p, int q) {
    setname(n);
    setprice(p);
    setquanity(q);
}

void Product::setname(const char* n) {
    strcpy_s(name, n);
}

void Product::setprice(float p) {
    price = p;
}

void Product::setquanity(int q) {
    quanity = q;
}

const char* Product::pullname() const {
    return name;
}

float Product::pullprice() const {
    return price;
}

int Product::pullquanity() const {
    return quanity;
}

void Product::showproduct() const {
    cout << name << ", $" << price << " (" << quanity << " amt)" << endl;
}

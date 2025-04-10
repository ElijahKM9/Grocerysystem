#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
private:
    char name[100];
    float price;
    int quanity;

public:
    Product();
    Product(const char* n, float p, int q);
    void setname(const char* n);
    void setprice(float p);
    void setquanity(int q);
    const char* pullname() const;
    float pullprice() const;
    int pullquanity() const;
    void showproduct() const;
    void set(const char* n, float p, int q);
};

#endif

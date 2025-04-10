#ifndef INTERFACE_H
#define INTERFACE_H

class Interface {
public:
    virtual void showCartMenu() = 0;
    virtual void browseDepartments() = 0;
    virtual ~Interface() {}
};


#endif

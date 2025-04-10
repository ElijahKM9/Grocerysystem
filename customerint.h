#include "interface.h"
#include "cart.h"


class Customerint : public Interface {
public:
    Customerint();
    void showCartMenu();
    void browseDepartments();

private:
    Cart cart;

    void listItemsInCart();
    void checkoutCart();
    void listDepartments();
    void listItemsInDepartment(int deptIndex);
};

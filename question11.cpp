#include <iostream>
using namespace std;


class User {
public:
    virtual void accessLevel() {
        cout << "General Access\n";
    }
};


class Employee : public User {
public:
    void accessLevel() override {
        cout << "Employee Access\n";
    }
};

/
class InventoryManager : public Employee {
public:
    void accessLevel() override {
        cout << "Full Inventory Management Access\n";
    }
};

int main() {
    InventoryManager mgr;
    mgr.accessLevel(); // Should print: Full Inventory Management Access
    return 0;
}

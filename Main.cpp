#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "clothes.h"

using namespace std;




int main() {

    showDataTypes();

    InventoryManager manager;

    //  pointers
    ClothingItem *ptrItem = new ClothingItem("Shirt", "M", 19.99);
    manager.addItem(*ptrItem);
    delete ptrItem; // free memory

    // Add
    manager.addItem(ClothingItem("Jeans", "L", 39.99));
    manager.addItem(ClothingItem("Jacket", "XL", 59.99));
    manager.addItem(ClothingItem("Skirt", "S", 24.99));
    manager.addItem(ClothingItem("T-Shirt", "M", 14.99));

    // Save
    manager.saveToFile("clothing.txt");

    // Load 
    manager.loadFromFile("clothing.txt");

    // Sort and search
    manager.sortItemsByName();

    string searchItem;
    cout << "\nEnter clothing item name to search: ";
    getline(cin, searchItem);

    int index = manager.binarySearchByName(searchItem);
    manager.displayItem(index);

    return 0;
}

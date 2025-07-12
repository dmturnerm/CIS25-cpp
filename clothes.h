#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Class to add the type of clothes
class ClothingItem {
public:
    string name;
    string size;
    float price;

    ClothingItem() {}
    ClothingItem(string n, string s, float p) : name(n), size(s), price(p) {}
};

//  clothing inventory
class InventoryManager {
private:
    ClothingItem items[5]; 
    int count;

public:
    InventoryManager() : count(0) {}

    void addItem(ClothingItem item) {
        if (count < 5) {
            items[count++] = item;
        }
    }

    void saveToFile(const string &filename) {
        ofstream file(filename);
        for (int i = 0; i < count; i++) {
            file << items[i].name << "," << items[i].size << "," << items[i].price << endl;
        }
        file.close();
    }

    void loadFromFile(const string &filename) {
        ifstream file(filename);
        string name, size;
        float price;
        count = 0;

        while (getline(file, name, ',') && getline(file, size, ',') && file >> price) {
            file.ignore(); // skip newline
            items[count++] = ClothingItem(name, size, price);
        }
        file.close();
    }

    void sortClothes(ClothingItem items[], int count) {
    std::sort(items, items + count, [](const ClothingItem& a, const ClothingItem& b) -> bool {
        return a.size < b.size; 
    });
}

    int binarySearchByName(const string &target) {
        int left = 0, right = count - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (items[mid].name == target)
                return mid;
            else if (items[mid].name < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1; // not found
    }

    void displayItem(int index) {
        if (index >= 0 && index < count) {
            cout << "Found: " << items[index].name << " | Size: " << items[index].size
                 << " | Price: $" << items[index].price << endl;
        } else {
            cout << "Item not found." << endl;
        }
    }
};

// to show data types and sizes
void showDataTypes() {
    cout << "Data Types and Their Sizes:\n";
    cout << "int: " << sizeof(int) << " bytes\n";
    cout << "float: " << sizeof(float) << " bytes\n";
    cout << "double: " << sizeof(double) << " bytes\n";
    cout << "char: " << sizeof(char) << " byte\n";
    cout << "bool: " << sizeof(bool) << " byte\n";
    cout << "string: " << sizeof(string) << " bytes (object)\n";
}
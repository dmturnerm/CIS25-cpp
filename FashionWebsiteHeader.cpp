#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// limits the amount of items in each catergory
const int MAX_TOPS = 10;
const int MAX_BOTTOMS = 10;

//  class to represent one piece of clothing 
class ClothingItem {
public:
    string name;
    string color;
    string type; 

    ClothingItem() {}
    ClothingItem(string n, string c, string t) : name(n), color(c), type(t) {}

    void display() const {
        cout << name << " (" << color << ", " << type << ")" << endl;
    }
};

// Wardrobe class holds collections of clothing items and generates outfits
class Wardrobe {
private:
    ClothingItem tops[MAX_TOPS];
    ClothingItem bottoms[MAX_BOTTOMS];
    int topCount = 0;
    int bottomCount = 0;

public:
    void addItem(const ClothingItem &item) {
        if (item.type == "top" && topCount < MAX_TOPS) {
            tops[topCount++] = item;
        } else if (item.type == "bottom" && bottomCount < MAX_BOTTOMS) {
            bottoms[bottomCount++] = item;
        }
    }

    void generateOutfits() const {
        cout << "\nGenerated Outfits:\n";
        for (int i = 0; i < topCount; ++i) {
            for (int j = 0; j < bottomCount; ++j) {
                cout << "Outfit: ";
                tops[i].display();
                cout << "       ";
                bottoms[j].display();
                cout << endl;
            }
        }
    }

    // Binary search for a top by name
    ClothingItem* binarySearchTop(const string &target) {
        int low = 0, high = topCount - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (tops[mid].name == target) return &tops[mid];
            if (tops[mid].name < target) low = mid + 1;
            else high = mid - 1;
        }
        return nullptr;
    }

    void sortTops() {
        sort(tops, tops + topCount, [](ClothingItem &a, ClothingItem &b) {
            return a.name < b.name;
        });
    }

    void loadFromFile(const string &filename) {
        ifstream infile(filename);
        if (!infile) {
            cerr << "Unable to open file: " << filename << endl;
            return;
        }
        string name, color, type;
        while (infile >> name >> color >> type) {
            addItem(ClothingItem(name, color, type));
        }
        infile.close();
    }

    void saveToFile(const string &filename) {
        ofstream outfile(filename);
        for (int i = 0; i < topCount; ++i) {
            outfile << tops[i].name << ' ' << tops[i].color << ' ' << tops[i].type << endl;
        }
        for (int i = 0; i < bottomCount; ++i) {
            outfile << bottoms[i].name << ' ' << bottoms[i].color << ' ' << bottoms[i].type << endl;
        }
        outfile.close();
    }
};
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    Wardrobe myWardrobe;
    myWardrobe.loadFromFile("wardrobe.txt");

    myWardrobe.sortTops();

    cout << "\nSearching for top: tshirt" << endl;
    ClothingItem* found = myWardrobe.binarySearchTop("tshirt");
    if (found != nullptr) {
        cout << "Found top: ";
        found->display();
    } else {
        cout << "Top not found." << endl;
    }

    myWardrobe.generateOutfits();

    myWardrobe.saveToFile("wardrobe_out.txt");

    return 0;
}


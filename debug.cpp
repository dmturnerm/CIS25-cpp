#include <iostream>
using namespace std;
int main() {    
    float n1; 
    float n2;
    float n3;

    cout << "Enter a number: ";
    cin >> n1;
    cout << "Enter a number: "; 
    cin >> n2;
    cout << "Enter a number: ";
    cin>> n3;
     if(n1 == n2 && n1 >= n3)
     {
        cout << "Largest number: " << n1;
     }
     if(n2 == n1 && n2 >= n3)
     { cout << "Largest number: " << n1;
    if(n3 >= n1 && n3 >= n2){
    cout << "Largest number: " << n2;
}
    return 0;
}

}

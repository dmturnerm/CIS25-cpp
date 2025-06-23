#include <iostream> 
using namespace std; 
int main() { 
    int quantity;
    float cost;
    string itemName;

    cout<<"Enter Item Name:";
    cin>>itemName;
    cout<<"Enter quantity:";
    cin >>quantity;
    cout<<"Enter cost:";
    cin>> cost;
    cout<<"Total cost for"<<itemName<<" :$"<<(quantity*cost)<<endl;
    return 0;

} 



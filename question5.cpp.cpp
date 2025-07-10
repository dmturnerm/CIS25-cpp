#include <iostream> 
#include <string> 
 using namespace std;

struct Student { 
 int id; 
 string name; 
 double gpa; 
}; 
 
int main() { 
 Student students[3];  
 
 

 students[0] = {101, "Michael", 3.8}; 
 students[1] = {102, "Lakisha", 3.5}; 
 students[2] = {103, "Charlie", 3.9}; 

 for (int i = 0; i < 3; ++i) { 
 cout << "Student ID: " << students[i].id  
<< ", Name: " << students[i].name  
<< ", GPA: " << students[i].gpa << std::endl; 
 } 
 
 return 0; 
} 
 

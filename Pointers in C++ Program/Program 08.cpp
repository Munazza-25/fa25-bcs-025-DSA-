#include <iostream>
using namespace std;
int* getPointer() {
    int x = 16;

    return &x; 
}
int main() {    
   
    int* ptr = getPointer();  
     cout << *ptr; 
    return 0;
}


#include <iostream>
using namespace std;
void modifyValue(int &x) {  
    x = 40;  
}
int main() {
    int a = 10;  
    modifyValue(a);
    
    cout << a;
    return 0;
}


#include <iostream>
using namespace std;
int main() {
   int x = 18;
    int& ref = x;

    cout << ref << endl;    
    ref = 66;
    cout << ref;
    return 0;
}


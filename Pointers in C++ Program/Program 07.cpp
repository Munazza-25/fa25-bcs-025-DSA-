#include <iostream>
using namespace std;
int main() {
    int x = 36;

    void* ptr = &x;

    cout << "The Value pointed by void pointer is: ";
    cout<< *(static_cast<int*>(ptr));
    return 0;
}


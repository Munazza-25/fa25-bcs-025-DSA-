#include <iostream>
using namespace std;
int& getMax(int &a, int &b) {
    return (a > b) ? a : b;  
}
int main() {
    int x = 10;
	int y = 20;
    int &maxVal = getMax(x, y); 
    maxVal = 30;  
    cout << "x = " << x << " , y = " << y;
    return 0;
}


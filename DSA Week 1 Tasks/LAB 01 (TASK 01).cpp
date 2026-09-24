#include <iostream>
using namespace std;
int main()
{
    int start, stop;
    int sum = 0;
    cout << "Enter starting value: ";
    cin >> start;
    cout << "Enter stopping value: ";
    cin >> stop;
    int x = start;
    while (x <= stop)
    {
        sum = sum + x * x;
        x++;
    }
    cout << "Sum of squares = " << sum;
    return 0;
}


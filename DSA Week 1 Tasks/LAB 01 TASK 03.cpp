#include <iostream>
using namespace std;
class ArrayList
{
private:
    int arr[CAPACITY];
    int size;
public:
    ArrayList()
  {
        size = 0;
    }
    void insertEnd(int value)
    {
        if (size < CAPACITY)
        {
            arr[size] = value;
            size++;
        }
    }
    void display()
    {
        int i = 0;
        while (i < size)
        {
            cout << arr[i] << " ";
            i++;
        }
        cout << endl;
    }
    void linearSearch(int value)
    {
        int i = 0;
        while (i < size)
        {
            if (arr[i] == value)
            {
                cout << "Value found at index " << i << endl;
                return;
            }
            i++;
        }
        cout << "Value not found." << endl;
    }
};
int main()
{
    ArrayList list;
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);
    list.insertEnd(50);
    cout << "Array List: ";
    list.display();
    int value;
    cout << "Enter value to search: ";
    cin >> value;
    list.linearSearch(value);
    return 0;
}


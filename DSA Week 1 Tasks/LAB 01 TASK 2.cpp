
#include <iostream>
#define CAPACITY 20
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
        if (size == CAPACITY)
        {
            cout << "List is full." << endl;
            return;
        }

        arr[size] = value;
        size++;
    }

    void insertStart(int value)
    {
        if (size == CAPACITY)
        {
            cout << "List is full." << endl;
            return;
        }

        int i = size;

        while (i > 0)
        {
            arr[i] = arr[i - 1];
            i--;
        }

        arr[0] = value;
        size++;
    }

    void insertAfter(int oldValue, int value)
    {
        if (size == CAPACITY)
        {
            cout << "List is full." << endl;
            return;
        }

        int i = 0;

        while (i < size && arr[i] != oldValue)
        {
            i++;
        }

        if (i == size)
        {
            cout << "Value not found." << endl;
            return;
        }

        int j = size;

        while (j > i + 1)
        {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[i + 1] = value;
        size++;
    }

    void insertBefore(int oldValue, int value)
    {
        if (size == CAPACITY)
        {
            cout << "List is full." << endl;
            return;
        }

        int i = 0;

        while (i < size && arr[i] != oldValue)
        {
            i++;
        }

        if (i == size)
        {
            cout << "Value not found." << endl;
            return;
        }

        int j = size;

        while (j > i)
        {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[i] = value;
        size++;
    }

    void display()
    {
        if (size == 0)
        {
            cout << "List is empty." << endl;
            return;
        }

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    void deleteEnd()
    {
        if (size == 0)
        {
            cout << "List is empty." << endl;
            return;
        }

        size--;
    }

    void deleteStart()
    {
        if (size == 0)
        {
            cout << "List is empty." << endl;
            return;
        }

        int i = 0;

        while (i < size - 1)
        {
            arr[i] = arr[i + 1];
            i++;
        }

        size--;
    }

    void deleteSpecific(int value)
    {
        int i = 0;

        while (i < size && arr[i] != value)
        {
            i++;
        }

        if (i == size)
        {
            cout << "Value not found." << endl;
            return;
        }

        while (i < size - 1)
        {
            arr[i] = arr[i + 1];
            i++;
        }

        size--;
    }
};

int main()
{
    ArrayList list;

    list.insertEnd(10);
    list.insertEnd(10);
    list.insertEnd(40);

    cout << "After inserting at end: ";
    list.display();

    list.insertStart(5);

    cout << "After inserting at start: ";
    list.display();

    list.insertAfter(15, 30);

    cout << "After inserting after 20: ";
    list.display();

    list.insertBefore(40, 20);

    cout << "After inserting before 30: ";
    list.display();

    list.deleteEnd();

    cout << "After deleting from end: ";
    list.display();

    list.deleteStart();

    cout << "After deleting from start: ";
    list.display();

    list.deleteSpecific(20);

    cout << "After deleting 20: ";
    list.display();

    return 0;
}


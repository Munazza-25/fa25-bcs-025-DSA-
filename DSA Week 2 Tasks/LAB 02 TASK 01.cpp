#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* first = NULL;
Node* last = NULL;
void insertEnd(int value)
{
    Node* p = new Node;
    p->data = value;
    p->next = NULL;
 if (first == NULL)
    {
        first = p;
        last = p;
    }
    else
    {
        last->next = p;
        last = p;
    }
}
void display()
{
    Node* p = first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void reverseLoop()
{
    Node* p = first;
    Node* previous = NULL;
    Node* nextNode;
    while (p != NULL)
    {
        nextNode = p->next;
        p->next = previous;
        previous = p;
        p = nextNode;
    }

    first = previous;
}
void reverseRecursive(Node* p)
{
    if (p == NULL)
        return;
    reverseRecursive(p->next);
    cout << p->data << " ";
}
int main()
{
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);
    insertEnd(60);
    cout << "Original List: ";
    display();
    cout << "Reverse using recursion: ";
    reverseRecursive(first);
    cout << endl;
    reverseLoop();
    cout << "Reverse using loop: ";
    display();
    return 0;
}


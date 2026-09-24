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
    else    {
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
void findOccurrences(int value)
{
    Node* p = first;
    int count = 0;
    int position = 1;
    while (p != NULL)
    {
        if (p->data == value)   {
            cout << "Value found at position " << position << endl;
            count++;   }
        p = p->next;
        position++;
    }
    if (count == 0)   {
        cout << "Value not found." << endl;
    }
    else    {
        cout << "Total occurrences = " << count << endl;
    }
}
int main(){
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);
    insertEnd(60);
    insertEnd(70);
    cout << "Linked List: ";
    display();
    int value;
    cout << "Enter the value you want to search: ";
    cin >> value;
    findOccurrences(value);
    
    return 0;
}      


#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
void insertEnd(Node*& first, Node*& last, int value)
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
void display(Node* first)
{
    Node* p = first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
Node* mergeLists(Node* first1, Node* first2)
{
    Node* first3 = NULL;
    Node* last3 = NULL;
    Node* p = first1;
    while (p != NULL)
    {
        insertEnd(first3, last3, p->data);
        p = p->next;
    }
    p = first2;
    while (p != NULL)
    {
        insertEnd(first3, last3, p->data);
        p = p->next;
    }
    return first3;
}
int main()
{
    Node* first1 = NULL;
    Node* last1 = NULL;
    Node* first2 = NULL;
    Node* last2 = NULL;
    insertEnd(first1, last1, 10);
    insertEnd(first1, last1, 20);
    insertEnd(first1, last1, 30);
    insertEnd(first2, last2, 40);
    insertEnd(first2, last2, 50);
    insertEnd(first2, last2, 60);
    cout << "First List: ";
    display(first1);

    cout << "Second List: ";
    display(first2);
    Node* first3 = mergeLists(first1, first2);
    cout << "Third List: ";
    display(first3);
    return 0;
}


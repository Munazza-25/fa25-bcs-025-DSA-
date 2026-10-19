
#include <iostream>
using namespace std;

// Create a node for the doubly linked list
struct Node
{
    int data;
    Node* prev;
    Node* next;
};

// Start of the list
Node* head = NULL;

// Insert a value at the end of the list
void insertEnd(int value)
{
    Node* newNode = new Node;

    // Store the value and initialize pointers
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    // If the list is empty, make this the first node
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // Move to the last node
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Connect the new node at the end
    temp->next = newNode;
    newNode->prev = temp;
}

// Display all values in the list
void display()
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Reverse the doubly linked list
void reverseList()
{
    Node* current = head;
    Node* temp = NULL;

    // Swap the next and previous pointers of every node
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node in the original list
        current = current->prev;
    }

    // Update head to the new first node
    if (temp != NULL)
    {
        head = temp->prev;
    }
}

int main()
{
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    // Take values from the user
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;
        insertEnd(value);
    }

    cout << "Original list: ";
    display();

    // Reverse the list
    reverseList();

    cout << "Reversed list: ";
    display();

    return 0;
}


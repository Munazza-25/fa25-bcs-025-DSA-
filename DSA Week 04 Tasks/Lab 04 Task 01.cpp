
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* tail = NULL;

// Insert a new node at the end
void insertEnd(int value)
{
    Node* newNode = new Node;
    newNode->data = value;

    // Create a circular list with one node
    if (tail == NULL)
    {
        tail = newNode;
        tail->next = tail;
    }
    else
    {
        // Connect the new node before the first node
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

// Display the circular linked list
void display()
{
    if (tail == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = tail->next;

    // Visit each node exactly once
    do
    {
        cout << current->data << " ";
        current = current->next;
    }
    while (current != tail->next);

    cout << endl;
}

// Delete nodes whose data is even or odd
void deleteByParity(bool deleteEven)
{
    if (tail == NULL)
        return;

    // Count the original number of nodes
    int count = 1;
    Node* current = tail->next;

    while (current != tail)
    {
        count++;
        current = current->next;
    }

    // Start from the first node
    current = tail->next;
    Node* previous = tail;

    // Check every original node once
    for (int i = 0; i < count; i++)
    {
        bool shouldDelete;

        if (deleteEven)
            shouldDelete = (current->data % 2 == 0);
        else
            shouldDelete = (current->data % 2 != 0);

        if (shouldDelete)
        {
            Node* temp = current;

            // Handle the case where only one node exists
            if (current == tail && current->next == current)
            {
                tail = NULL;
                delete temp;
                current = NULL;
                break;
            }

            // Remove the current node from the circle
            previous->next = current->next;

            // Update tail if the last node is deleted
            if (current == tail)
                tail = previous;

            current = previous->next;
            delete temp;
        }
        else
        {
            // Move to the next node
            previous = current;
            current = current->next;
        }
    }
}

int main()
{
    int n, value, choice;

    cout << "Enter number of nodes: ";
    cin >> n;

    // Create the circular linked list
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;
        insertEnd(value);
    }

    cout << "Original list: ";
    display();

    cout << "1. Delete nodes with even values" << endl;
    cout << "2. Delete nodes with odd values" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    // Delete the selected values
    if (choice == 1)
        deleteByParity(true);
    else if (choice == 2)
        deleteByParity(false);
    else
        cout << "Invalid choice." << endl;

    cout << "Updated list: ";
    display();

    return 0;
}


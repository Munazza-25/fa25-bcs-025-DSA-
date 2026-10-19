
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* tail = NULL;

// Insert a value at the end of the circular list
void insertEnd(int value)
{
    Node* newNode = new Node;
    newNode->data = value;

    // Handle the empty list
    if (tail == NULL)
    {
        tail = newNode;
        tail->next = tail;
    }
    else
    {
        // Connect the new node to the circular list
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

// Display all nodes in the list
void display()
{
    if (tail == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = tail->next;

    // Stop after visiting the first node again
    do
    {
        cout << current->data << " ";
        current = current->next;
    }
    while (current != tail->next);

    cout << endl;
}

// Delete nodes at even positions
void deleteEvenPositions()
{
    if (tail == NULL)
        return;

    // Count nodes before starting deletion
    int count = 1;
    Node* current = tail->next;

    while (current != tail)
    {
        count++;
        current = current->next;
    }

    // Start at position one
    current = tail->next;
    Node* previous = tail;

    // Check the original position of every node
    for (int position = 1; position <= count; position++)
    {
        if (position % 2 == 0)
        {
            Node* temp = current;

            // Handle a list containing only one node
            if (current == tail && current->next == current)
            {
                tail = NULL;
                delete temp;
                return;
            }

            // Remove the current node
            previous->next = current->next;

            // Update tail when deleting the last node
            if (current == tail)
                tail = previous;

            current = previous->next;
            delete temp;
        }
        else
        {
            // Keep odd-positioned nodes
            previous = current;
            current = current->next;
        }
    }
}

int main()
{
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    // Build the circular linked list
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;
        insertEnd(value);
    }

    cout << "Original list: ";
    display();

    // Remove nodes at positions 2, 4, 6, and so on
    deleteEvenPositions();

    cout << "After deleting even positions: ";
    display();

    return 0;
}


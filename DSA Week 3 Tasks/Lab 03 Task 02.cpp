
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

// Insert a value at the end
void insertEnd(int value)
{
    Node* newNode = new Node;

    // Store the value and initialize pointers
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    // Handle an empty list
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

    // Link the new node with the last node
    temp->next = newNode;
    newNode->prev = temp;
}

// Display the list
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

// Search for a value and display all its positions
void searchValue(int value)
{
    Node* temp = head;
    int position = 1;
    bool found = false;

    // Check every node in the list
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << value << " found at position "
                 << position << endl;

            found = true;
        }

        temp = temp->next;
        position++;
    }

    // Display a message if the value does not exist
    if (found == false)
    {
        cout << value << " not found in the list." << endl;
    }
}

int main()
{
    int n, value;
    int firstValue, secondValue;

    cout << "Enter number of nodes: ";
    cin >> n;

    // Create the doubly linked list
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;
        insertEnd(value);
    }

    cout << "Doubly linked list: ";
    display();

    // Take two values to search
    cout << "Enter first value to search: ";
    cin >> firstValue;

    cout << "Enter second value to search: ";
    cin >> secondValue;

    // Search for both values
    searchValue(firstValue);
    searchValue(secondValue);

    return 0;
}


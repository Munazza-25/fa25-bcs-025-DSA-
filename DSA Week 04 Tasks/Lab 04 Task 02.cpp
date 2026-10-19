
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* tail = NULL;

// Insert a person into the circular list
void insertEnd(int value)
{
    Node* newNode = new Node;
    newNode->data = value;

    // Make the first node point to itself
    if (tail == NULL)
    {
        tail = newNode;
        tail->next = tail;
    }
    else
    {
        // Add the new person at the end
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

// Solve the Josephus problem
void josephus(int k)
{
    if (tail == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = tail->next;
    Node* previous = tail;

    cout << "Elimination order: ";

    // Continue until only one person remains
    while (current->next != current)
    {
        // Count k positions in the circle
        for (int i = 1; i < k; i++)
        {
            previous = current;
            current = current->next;
        }

        // Display the person being eliminated
        cout << current->data << " ";

        // Remove the person from the circle
        previous->next = current->next;

        // Update tail if the last node is removed
        if (current == tail)
            tail = previous;

        Node* temp = current;
        current = current->next;
        delete temp;
    }

    // The remaining node is the survivor
    cout << endl;
    cout << "Surviving person: " << current->data << endl;

    // Release the final node
    delete current;
    tail = NULL;
}

int main()
{
    int n, k;

    cout << "Enter number of people: ";
    cin >> n;

    // Check the number of people
    if (n <= 0)
    {
        cout << "Number of people must be positive." << endl;
        return 0;
    }

    cout << "Enter counting number k: ";
    cin >> k;

    // Check the counting number
    if (k <= 0)
    {
        cout << "k must be positive." << endl;
        return 0;
    }

    // Create the circle using person numbers
    for (int i = 1; i <= n; i++)
    {
        insertEnd(i);
    }

    // Find the elimination order and survivor
    josephus(k);

    return 0;
}


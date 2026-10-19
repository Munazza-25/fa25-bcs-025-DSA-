
#include <iostream> // Used for input and output
using namespace std; // Allows us to use cout directly

struct Node // Defines one linked-list node
{
    int data; // Stores the element
    Node* next; // Points to the next node
};

class Queue // Creates a queue using linked nodes
{
    Node* front; // Points to the first node
    Node* rear; // Points to the last node
    int count; // Stores the number of elements

public:
    Queue() // Initializes an empty queue
    {
        front = NULL; // No first node exists
        rear = NULL; // No last node exists
        count = 0; // Starts with zero elements
    }

    bool isEmpty() // Checks whether the queue is empty
    {
        return front == NULL; // Returns true if no node exists
    }

    int size() // Returns the queue size
    {
        return count; // Gives the current number of elements
    }

    void enqueue(int x) // Adds an element at the rear
    {
        Node* n = new Node; // Creates a new node
        n->data = x; // Stores the given value
        n->next = NULL; // Marks it as the last node

        if (rear == NULL) // Checks whether the queue is empty
        {
            front = n; // Makes the new node the first node
            rear = n; // Makes the new node the last node
        }
        else // Runs when the queue already has elements
        {
            rear->next = n; // Connects the old rear to the new node
            rear = n; // Updates the rear pointer
        }

        count++; // Increases the queue size
    }

    int dequeue() // Removes the front element
    {
        if (isEmpty()) return -1; // Handles an empty queue

        Node* temp = front; // Saves the first node
        int x = temp->data; // Saves the value to return
        front = front->next; // Moves front to the next node

        if (front == NULL) // Checks whether the queue is now empty
            rear = NULL; // Resets the rear pointer

        delete temp; // Frees the removed node
        count--; // Decreases the queue size

        return x; // Returns the removed value
    }

    void display() // Prints all queue elements
    {
        int n = count; // Saves the original queue size

        while (n > 0) // Visits every element once
        {
            int x = dequeue(); // Removes the front element
            cout << x << " "; // Prints the value
            enqueue(x); // Adds the value back to the queue
            n--; // Moves to the next element
        }

        cout << endl; // Moves to the next line
    }
};

void selectionSort(Queue& q) // Sorts the queue using selection sort
{
    Queue sorted; // Creates a queue for sorted elements
    int n = q.size(); // Saves the original queue size

    for (int i = 0; i < n; i++) // Finds one minimum per pass
    {
        int minimum = q.dequeue(); // Takes the first unsorted element
        int remaining = n - i - 1; // Counts the other unsorted elements

        q.enqueue(minimum); // Returns the first element to the queue

        for (int j = 0; j < remaining; j++) // Checks the remaining elements
        {
            int x = q.dequeue(); // Takes the next element

            if (x < minimum) // Checks whether x is smaller
                minimum = x; // Updates the minimum value

            q.enqueue(x); // Returns the element to the queue
        }

        bool removed = false; // Tracks whether minimum was removed

        for (int j = 0; j < remaining + 1; j++) // Searches for the minimum
        {
            int x = q.dequeue(); // Takes the next element

            if (x == minimum && !removed) // Removes one minimum occurrence
                removed = true; // Marks the minimum as removed
            else // Keeps all other elements
                q.enqueue(x); // Returns the element to the queue
        }

        sorted.enqueue(minimum); // Adds the minimum to sorted queue
    }

    q = sorted; // Transfers the sorted queue to q
}

int main() // Program execution starts here
{
    Queue q; // Creates a linked-list-based queue

    q.enqueue(5); // Adds 5
    q.enqueue(2); // Adds 2
    q.enqueue(4); // Adds 4
    q.enqueue(1); // Adds 1
    q.enqueue(3); // Adds 3

    cout << "Original queue: "; // Displays the original queue
    q.display(); // Prints the original elements

    selectionSort(q); // Sorts the queue

    cout << "Sorted queue: "; // Displays the sorted queue
    q.display(); // Prints the sorted elements

    return 0; // Ends the program
}


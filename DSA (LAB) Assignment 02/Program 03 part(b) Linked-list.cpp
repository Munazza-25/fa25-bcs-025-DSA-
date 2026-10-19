
#include <iostream> // Used for input and output
using namespace std; // Allows us to use cout directly

struct Node // Defines one linked-list node
{
    int data; // Stores the element
    Node* next; // Points to the next node
};

class Queue // Creates a linked-list queue
{
    Node *front, *rear; // Track the first and last nodes
    int count; // Stores the number of elements

public:
    Queue() // Initializes an empty queue
    {
        front = rear = NULL; // Both pointers start empty
        count = 0; // Starts with zero elements
    }

    bool isEmpty() // Checks whether the queue is empty
    {
        return front == NULL; // Checks the front pointer
    }

    int size() // Returns the queue size
    {
        return count; // Gives the current number of elements
    }

    void enqueue(int x) // Adds an element at the rear
    {
        Node* n = new Node; // Creates a new node
        n->data = x; // Stores the value
        n->next = NULL; // Marks it as the last node

        if (rear == NULL) // Checks whether the queue is empty
            front = rear = n; // Makes n the first and last node
        else // Runs when the queue already has elements
        {
            rear->next = n; // Connects the old rear to n
            rear = n; // Updates the rear pointer
        }

        count++; // Increases the queue size
    }

    int dequeue() // Removes the front element
    {
        if (isEmpty()) return -1; // Handles an empty queue

        Node* temp = front; // Saves the first node
        int x = temp->data; // Saves its value
        front = front->next; // Moves front forward

        if (front == NULL) rear = NULL; // Resets rear if empty

        delete temp; // Frees the removed node
        count--; // Decreases the queue size
        return x; // Returns the removed value
    }

    void display() // Prints the queue elements
    {
        int n = count; // Saves the queue size

        while (n--) // Visits every element once
        {
            int x = dequeue(); // Removes the front element
            cout << x << " "; // Prints the value
            enqueue(x); // Adds it back to the queue
        }

        cout << endl; // Moves to the next line
    }
};

void bubbleSort(Queue& q) // Sorts the queue using bubble sort
{
    int n = q.size(); // Saves the total number of elements

    for (int i = 0; i < n - 1; i++) // Performs sorting passes
    {
        Queue temp; // Stores the result of the current pass
        int previous = q.dequeue(); // Takes the first element

        for (int j = 0; j < n - 1; j++) // Compares adjacent elements
        {
            int current = q.dequeue(); // Takes the next element

            if (previous > current) // Checks if they are out of order
            {
                temp.enqueue(current); // Places the smaller value first
            }
            else // Runs if previous is already in order
            {
                temp.enqueue(previous); // Places previous in the queue
                previous = current; // Keeps current for the next comparison
                continue; // Continues with the next pair
            }

            previous = previous; // Keeps the larger value for comparison
        }

        temp.enqueue(previous); // Adds the last remaining value
        q = temp; // Updates the queue for the next pass
    }
}

int main() // Program execution starts here
{
    Queue q; // Creates a queue

    q.enqueue(5); // Adds 5
    q.enqueue(2); // Adds 2
    q.enqueue(4); // Adds 4
    q.enqueue(1); // Adds 1
    q.enqueue(3); // Adds 3

    bubbleSort(q); // Sorts the queue
    q.display(); // Prints the sorted elements

    return 0; // Ends the program
}


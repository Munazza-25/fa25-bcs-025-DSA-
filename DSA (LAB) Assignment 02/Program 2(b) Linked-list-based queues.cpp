
#include <iostream> // Used for input and output
using namespace std; // Allows us to use cout directly

struct Node // Defines one queue node
{
    int data; // Stores the element
    Node* next; // Points to the next node
};

class Queue // Creates a queue using linked nodes
{
    Node *front, *rear; // Track the first and last nodes

public:
    Queue() // Initializes an empty queue
    {
        front = rear = NULL; // Both pointers start empty
    }

    bool isEmpty() // Checks whether the queue is empty
    {
        return front == NULL; // No front node means empty
    }

    void enqueue(int x) // Adds an element at the rear
    {
        Node* n = new Node; // Creates a new node
        n->data = x; // Stores the value
        n->next = NULL; // New last node points nowhere

        if (rear == NULL) // Checks whether the queue is empty
            front = rear = n; // Makes n the first and last node
        else // Runs when the queue already has elements
        {
            rear->next = n; // Connects the old rear to n
            rear = n; // Updates the rear pointer
        }
    }

    int dequeue() // Removes the front element
    {
        if (isEmpty()) return -1; // Handles an empty queue

        Node* temp = front; // Saves the first node
        int x = temp->data; // Saves its value
        front = front->next; // Moves front to the next node

        if (front == NULL) rear = NULL; // Resets rear if now empty

        delete temp; // Frees the removed node
        return x; // Returns the removed value
    }
};

class Stack // Creates a stack using two queues
{
    Queue q1, q2; // Declares two linked-list queues

public:
    void push(int x) // Adds an element to the stack
    {
        q2.enqueue(x); // Adds the newest element first

        while (!q1.isEmpty()) // Moves all older elements
            q2.enqueue(q1.dequeue()); // Places them behind x

        Queue temp = q1; // Saves the empty queue
        q1 = q2; // Stores the new order in q1
        q2 = temp; // Keeps q2 empty for the next push
    }

    int pop() // Removes the top stack element
    {
        return q1.dequeue(); // Removes the newest element
    }
};

int main() // Program execution starts here
{
    Stack s; // Creates a stack

    s.push(10); // Pushes 10
    s.push(20); // Pushes 20
    s.push(30); // Pushes 30

    cout << s.pop() << endl; // Prints 30
    cout << s.pop() << endl; // Prints 20
    cout << s.pop() << endl; // Prints 10

    return 0; // Ends the program
}


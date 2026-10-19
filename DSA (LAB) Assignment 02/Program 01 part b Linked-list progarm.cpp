
#include <iostream> // Used for input and output
using namespace std; // Allows us to use cout directly

struct Node // Defines one node of the linked list
{
    int data; // Stores the element
    Node* next; // Points to the next node
};

class Stack // Creates a stack using linked nodes
{
    Node* top; // Points to the top node

public:
    Stack() // Initializes an empty stack
    {
        top = NULL; // No node exists initially
    }

    bool isEmpty() // Checks whether the stack is empty
    {
        return top == NULL; // True means there is no node
    }

    void push(int x) // Adds a new element
    {
        Node* n = new Node; // Creates a new node
        n->data = x; // Stores the given value
        n->next = top; // Connects it to the previous top
        top = n; // Makes the new node the top
    }

    int pop() // Removes the top element
    {
        if (isEmpty()) return -1; // Handles an empty stack

        Node* temp = top; // Saves the top node
        int x = temp->data; // Saves its value
        top = top->next; // Moves top to the next node
        delete temp; // Frees the removed node

        return x; // Returns the removed value
    }
};

class Queue // Creates a queue using two stacks
{
    Stack s1, s2; // Declares two linked-list stacks

public:
    void enqueue(int x) // Adds an element to the queue
    {
        s1.push(x); // Adds the element to s1
    }

    int dequeue() // Removes the oldest element
    {
        if (s1.isEmpty() && s2.isEmpty()) // Checks both stacks
            return -1; // Queue is empty

        if (s2.isEmpty()) // Transfers only when s2 is empty
        {
            while (!s1.isEmpty()) // Moves every available element
                s2.push(s1.pop()); // Reverses the element order
        }

        return s2.pop(); // Removes the oldest element
    }
};

int main() // Program execution starts here
{
    Queue q; // Creates a queue

    q.enqueue(10); // Adds 10
    q.enqueue(20); // Adds 20
    q.enqueue(30); // Adds 30

    cout << q.dequeue() << endl; // Prints 10
    cout << q.dequeue() << endl; // Prints 20
    cout << q.dequeue() << endl; // Prints 30

    return 0; // Ends the program
}


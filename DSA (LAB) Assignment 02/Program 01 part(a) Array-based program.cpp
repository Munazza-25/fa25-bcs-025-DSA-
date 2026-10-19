
#include <iostream> // Used for input and output
using namespace std; // Allows us to use cout directly

class Stack // Creates a stack using an array
{
    int arr[100]; // Stores stack elements
    int top; // Keeps track of the top element

public:
    Stack() // Initializes an empty stack
    {
        top = -1; // -1 means the stack is empty
    }

    bool isEmpty() // Checks whether the stack is empty
    {
        return top == -1; // Returns true if no element exists
    }

    void push(int x) // Adds an element to the stack
    {
        if (top == 99) return; // Stops if the stack is full
        arr[++top] = x; // Moves top and stores the element
    }

    int pop() // Removes the top element
    {
        if (isEmpty()) return -1; // Handles an empty stack
        return arr[top--]; // Returns the top and decreases top
    }
};

class Queue // Creates a queue using two stacks
{
    Stack s1, s2; // Declares the two stacks

public:
    void enqueue(int x) // Adds an element to the queue
    {
        s1.push(x); // Stores the new element in the first stack
    }

    int dequeue() // Removes the oldest queue element
    {
        if (s1.isEmpty() && s2.isEmpty()) // Checks both stacks
            return -1; // Returns -1 if the queue is empty

        if (s2.isEmpty()) // Transfers elements only when needed
        {
            while (!s1.isEmpty()) // Continues until s1 becomes empty
                s2.push(s1.pop()); // Reverses the elements into s2
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


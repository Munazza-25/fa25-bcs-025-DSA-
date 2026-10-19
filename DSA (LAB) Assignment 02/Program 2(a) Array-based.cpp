
#include <iostream> // Used for input and output
using namespace std; // Allows us to use cout directly

class Queue // Creates a circular array queue
{
    int arr[100]; // Stores queue elements
    int front, rear, count; // Track queue positions and size

public:
    Queue() // Initializes an empty queue
    {
        front = 0; // Sets the first position
        rear = -1; // No last element exists
        count = 0; // Queue initially has zero elements
    }

    bool isEmpty() // Checks whether the queue is empty
    {
        return count == 0; // True when count is zero
    }

    void enqueue(int x) // Adds an element at the rear
    {
        if (count == 100) return; // Stops if the queue is full
        rear = (rear + 1) % 100; // Moves rear circularly
        arr[rear] = x; // Stores the new element
        count++; // Increases the number of elements
    }

    int dequeue() // Removes the front element
    {
        if (isEmpty()) return -1; // Handles an empty queue
        int x = arr[front]; // Saves the front value
        front = (front + 1) % 100; // Moves front forward
        count--; // Decreases the number of elements
        return x; // Returns the removed value
    }
};

class Stack // Creates a stack using two queues
{
    Queue q1, q2; // Declares two queues

public:
    void push(int x) // Adds an element to the stack
    {
        q2.enqueue(x); // Places the new element first

        while (!q1.isEmpty()) // Moves all older elements
            q2.enqueue(q1.dequeue()); // Places them behind x

        Queue temp = q1; // Saves the empty queue
        q1 = q2; // Makes q1 hold the new order
        q2 = temp; // Makes q2 empty for the next push
    }

    int pop() // Removes the most recently added element
    {
        return q1.dequeue(); // The newest element is at the front
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


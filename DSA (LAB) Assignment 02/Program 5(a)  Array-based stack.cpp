
#include <iostream> // Used for input and output
using namespace std; // Allows us to use cout directly

class Stack // Creates a stack using an array
{
    int arr[100]; // Stores stack elements
    int top; // Tracks the top element

public:
    Stack() // Initializes an empty stack
    {
        top = -1; // Indicates that the stack is empty
    }

    bool isEmpty() // Checks whether the stack is empty
    {
        return top == -1; // Returns true if no element exists
    }

    void push(int x) // Adds an element to the stack
    {
        if (top == 99) return; // Stops if the stack is full
        arr[++top] = x; // Moves top and stores the value
    }

    int pop() // Removes the top element
    {
        if (isEmpty()) return -1; // Handles an empty stack
        return arr[top--]; // Returns the top and decreases top
    }

    int peek() // Reads the top without removing it
    {
        if (isEmpty()) return -1; // Handles an empty stack
        return arr[top]; // Returns the top value
    }

    void display() // Prints elements from top to bottom
    {
        for (int i = top; i >= 0; i--) // Visits elements in stack order
            cout << arr[i] << " "; // Prints each element

        cout << endl; // Moves to the next line
    }
};

void insertionSort(Stack& input) // Sorts elements using two stacks
{
    Stack sorted; // Creates a second stack for sorting

    while (!input.isEmpty()) // Continues until input is empty
    {
        int x = input.pop(); // Takes the next element

        while (!sorted.isEmpty() && sorted.peek() > x) // Finds the correct position
            input.push(sorted.pop()); // Moves larger elements back

        sorted.push(x); // Places x in its correct position
    }

    while (!sorted.isEmpty()) // Moves the sorted elements back
        input.push(sorted.pop()); // Restores the sorted stack
}

int main() // Program execution starts here
{
    Stack s; // Creates a stack

    s.push(5); // Pushes 5
    s.push(2); // Pushes 2
    s.push(4); // Pushes 4
    s.push(1); // Pushes 1
    s.push(3); // Pushes 3

    insertionSort(s); // Sorts the stack
    s.display(); // Prints the sorted elements

    return 0; // Ends the program
}


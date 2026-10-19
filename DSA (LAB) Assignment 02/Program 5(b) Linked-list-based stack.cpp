
#include <iostream> // Used for input and output
using namespace std; // Allows us to use cout directly

struct Node // Defines one linked-list node
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
        return top == NULL; // Returns true if no node exists
    }

    void push(int x) // Adds an element to the stack
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

    int peek() // Reads the top without removing it
    {
        if (isEmpty()) return -1; // Handles an empty stack
        return top->data; // Returns the top value
    }

    void display() // Prints elements from top to bottom
    {
        Node* temp = top; // Starts at the top node

        while (temp != NULL) // Visits every node
        {
            cout << temp->data << " "; // Prints the node value
            temp = temp->next; // Moves to the next node
        }

        cout << endl; // Moves to the next line
    }
};

void insertionSort(Stack& input) // Sorts elements using two stacks
{
    Stack sorted; // Creates a second stack

    while (!input.isEmpty()) // Continues until input is empty
    {
        int x = input.pop(); // Takes the next element

        while (!sorted.isEmpty() && sorted.peek() > x) // Checks larger elements
            input.push(sorted.pop()); // Moves them back to input

        sorted.push(x); // Places x in its correct position
    }

    while (!sorted.isEmpty()) // Transfers the sorted elements back
        input.push(sorted.pop()); // Restores the sorted stack
}

int main() // Program execution starts here
{
    Stack s; // Creates a linked-list stack

    s.push(5); // Pushes 5
    s.push(2); // Pushes 2
    s.push(4); // Pushes 4
    s.push(1); // Pushes 1
    s.push(3); // Pushes 3

    insertionSort(s); // Sorts the stack
    s.display(); // Prints the sorted elements

    return 0; // Ends the program
}


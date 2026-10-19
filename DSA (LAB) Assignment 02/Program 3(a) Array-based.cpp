
#include <iostream> // Used for input and output
using namespace std; // Allows us to use cout directly

class Queue // Creates a queue using an array
{
    int arr[100]; // Stores the queue elements
    int front, rear, count; // Track positions and number of elements

public:
    Queue() // Initializes an empty queue
    {
        front = 0; // Sets the front position
        rear = -1; // Sets the rear position
        count = 0; // Starts with zero elements
    }

    bool isEmpty() // Checks whether the queue is empty
    {
        return count == 0; // Returns true if count is zero
    }

    int size() // Returns the number of elements
    {
        return count; // Gives the current queue size
    }

    void enqueue(int x) // Adds an element to the rear
    {
        if (count == 100) return; // Stops if the queue is full
        rear = (rear + 1) % 100; // Moves rear circularly
        arr[rear] = x; // Stores the element
        count++; // Increases the queue size
    }

    int dequeue() // Removes the front element
    {
        if (isEmpty()) return -1; // Handles an empty queue
        int x = arr[front]; // Saves the front value
        front = (front + 1) % 100; // Moves front forward
        count--; // Decreases the queue size
        return x; // Returns the removed value
    }

    void display() // Prints queue elements in order
    {
        int n = count; // Saves the original queue size

        while (n--) // Visits every element once
        {
            int x = dequeue(); // Removes the front element
            cout << x << " "; // Prints the element
            enqueue(x); // Adds it back to preserve the queue
        }

        cout << endl; // Moves to the next line
    }
};

void bubbleSort(Queue& q) // Sorts the queue using bubble sort
{
    int n = q.size(); // Saves the total number of elements

    for (int i = 0; i < n - 1; i++) // Performs sorting passes
    {
        Queue temp; // Stores the elements of this pass
        int previous = q.dequeue(); // Takes the first element

        for (int j = 0; j < n - 1; j++) // Compares adjacent elements
        {
            int current = q.dequeue(); // Takes the next element

            if (previous > current) // Checks their order
            {
                temp.enqueue(current); // Places the smaller value first
            }
            else // Runs when previous is smaller or equal
            {
                temp.enqueue(previous); // Places previous first
                previous = current; // Keeps the larger value for comparison
                continue; // Moves to the next comparison
            }

            previous = previous; // Keeps the larger value for the next comparison
        }

        temp.enqueue(previous); // Adds the last remaining value

        q = temp; // Stores the result of this pass in q
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


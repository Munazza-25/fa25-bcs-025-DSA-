
#include <iostream> // Used for input and output
using namespace std; // Allows us to use cout directly

class Queue // Creates a queue using an array
{
    int arr[100]; // Stores queue elements
    int front, rear, count; // Tracks queue positions and size

public:
    Queue() // Initializes an empty queue
    {
        front = 0; // Sets the front position
        rear = -1; // Sets the rear position
        count = 0; // Starts with zero elements
    }

    bool isEmpty() // Checks whether the queue is empty
    {
        return count == 0; // Returns true if no elements exist
    }

    int size() // Returns the number of elements
    {
        return count; // Gives the current queue size
    }

    void enqueue(int x) // Adds an element to the rear
    {
        if (count == 100) return; // Stops if the queue is full

        rear = (rear + 1) % 100; // Moves rear circularly
        arr[rear] = x; // Stores the new element
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

    void display() // Prints all queue elements
    {
        int n = count; // Saves the number of elements

        while (n > 0) // Visits each element once
        {
            int x = dequeue(); // Removes the front element
            cout << x << " "; // Prints the element
            enqueue(x); // Adds it back to preserve the queue
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

            if (x < minimum) // Checks if this value is smaller
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

    q = sorted; // Replaces the original queue with sorted values
}

int main() // Program execution starts here
{
    Queue q; // Creates an array-based queue

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



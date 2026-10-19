
#include <iostream>  // For input and output
using namespace std;

// Create a node for the linked-list queue
struct Node {
    int data;        // Store the queue element
    Node* next;      // Point to the next node
};

// Implement a dynamic queue using a linked list
class Queue {
private:
    Node* front;     // Point to the first node
    Node* rear;      // Point to the last node

public:
    // Initialize an empty queue
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Check whether the queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Insert an element at the rear
    void enqueue(int value) {
        Node* temp = new Node;  // Create a new node
        temp->data = value;     // Store the value
        temp->next = NULL;      // New rear has no next node

        if (isEmpty()) {
            front = temp;       // First node becomes the front
            rear = temp;        // First node also becomes the rear
        } else {
            rear->next = temp;  // Connect old rear to new node
            rear = temp;        // Update rear pointer
        }

        cout << value << " inserted." << endl;
    }

    // Remove an element from the front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;       // Keep the front node
        cout << "Removed: " << temp->data << endl;

        front = front->next;      // Move front to the next node

        if (front == NULL) {
            rear = NULL;          // Reset rear if queue becomes empty
        }

        delete temp;              // Free the removed node
    }

    // Display all queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;    // Start from the front

        cout << "Queue: ";
        while (current != NULL) {
            cout << current->data << " ";  // Display current value
            current = current->next;       // Move to next node
        }

        cout << endl;
    }

    // Release all nodes when the queue object is destroyed
    ~Queue() {
        while (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = NULL;
    }
};

int main() {
    Queue q;                // Create a queue object

    q.enqueue(10);          // Insert 10
    q.enqueue(20);          // Insert 20
    q.enqueue(30);          // Insert 30

    q.display();             // Display the queue

    q.dequeue();             // Remove the first element
    q.display();             // Display remaining elements

    q.dequeue();             // Remove the next element
    q.dequeue();             // Remove the last element
    q.dequeue();             // Test empty-queue handling

    q.display();             // Display the empty queue

    return 0;                // End the program
}


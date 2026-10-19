
#include <iostream>  // For input and output
using namespace std;

// Create a node for the doubly linked list
struct Node {
    int data;        // Store the element
    Node* next;      // Point to the next node
    Node* prev;      // Point to the previous node
};

// Implement a deque using a doubly linked list
class Deque {
private:
    Node* front;     // Point to the first node
    Node* rear;      // Point to the last node

public:
    // Initialize an empty deque
    Deque() {
        front = NULL;
        rear = NULL;
    }

    // Check whether the deque is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Insert an element at the front
    void insertFront(int value) {
        Node* temp = new Node;  // Create a new node
        temp->data = value;     // Store the value
        temp->prev = NULL;      // New front has no previous node
        temp->next = front;     // Link to the old front

        if (isEmpty()) {
            rear = temp;        // First node is also the rear
        } else {
            front->prev = temp; // Link old front back to new node
        }

        front = temp;           // Update front pointer
        cout << value << " inserted at front." << endl;
    }

    // Insert an element at the rear
    void insertRear(int value) {
        Node* temp = new Node;  // Create a new node
        temp->data = value;     // Store the value
        temp->next = NULL;      // New rear has no next node
        temp->prev = rear;      // Link to the old rear

        if (isEmpty()) {
            front = temp;       // First node is also the front
        } else {
            rear->next = temp;  // Link old rear to new node
        }

        rear = temp;            // Update rear pointer
        cout << value << " inserted at rear." << endl;
    }

    // Delete an element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = front;       // Keep the front node
        cout << "Deleted from front: " << temp->data << endl;

        front = front->next;      // Move front to next node

        if (front == NULL) {
            rear = NULL;          // Deque is now empty
        } else {
            front->prev = NULL;   // New front has no previous node
        }

        delete temp;              // Free the removed node
    }

    // Delete an element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = rear;        // Keep the rear node
        cout << "Deleted from rear: " << temp->data << endl;

        rear = rear->prev;        // Move rear to previous node

        if (rear == NULL) {
            front = NULL;         // Deque is now empty
        } else {
            rear->next = NULL;    // New rear has no next node
        }

        delete temp;              // Free the removed node
    }

    // Display elements from front to rear
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty." << endl;
            return;
        }

        Node* current = front;    // Start from the front

        cout << "Deque: ";
        while (current != NULL) {
            cout << current->data << " ";  // Display current value
            current = current->next;       // Move to next node
        }

        cout << endl;
    }

    // Release all remaining nodes
    ~Deque() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }

        rear = NULL;
    }
};

int main() {
    Deque d;                  // Create a deque object

    d.insertRear(10);         // Insert 10 at rear
    d.insertRear(20);         // Insert 20 at rear
    d.insertFront(5);         // Insert 5 at front
    d.display();              // Display all elements

    d.deleteFront();          // Delete from front
    d.display();              // Display remaining elements

    d.deleteRear();           // Delete from rear
    d.display();              // Display remaining elements

    d.deleteFront();          // Delete the last element
    d.deleteRear();           // Test deletion from an empty deque
    d.display();              // Display the empty deque

    return 0;                 // End the program
}


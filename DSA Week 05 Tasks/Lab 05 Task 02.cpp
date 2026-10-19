
#include <iostream>  // For input and output
#include <string>    // For string
#include <cctype>    // For checking letters and digits
using namespace std;

// Create a node for the linked-list stack
struct Node {
    char data;       // Store an operator
    Node* next;      // Point to the next node
};

// Implement a dynamic stack using linked list
class Stack {
private:
    Node* top;       // Point to the top node

public:
    Stack() {
        top = NULL;  // Initially, stack is empty
    }

    ~Stack() {
        while (top != NULL) {
            pop();   // Delete all remaining nodes
        }
    }

    bool isEmpty() {
        return top == NULL;  // Check whether stack is empty
    }

    void push(char value) {
        Node* temp = new Node;  // Create a new node
        temp->data = value;     // Store the value
        temp->next = top;       // Link new node to old top
        top = temp;             // Make new node the top
    }

    char pop() {
        if (isEmpty()) {
            return '\0';        // Return empty character
        }

        Node* temp = top;       // Keep the top node
        char value = temp->data; // Save its data
        top = top->next;        // Move top to next node
        delete temp;            // Free the removed node
        return value;           // Return removed value
    }

    char peek() {
        if (isEmpty()) {
            return '\0';         // No top value exists
        }
        return top->data;        // Return top without removing it
    }
};

// Return the precedence of an operator
int precedence(char op) {
    if (op == '^') return 3;     // Highest precedence
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;                    // Other characters
}

// Convert infix expression to postfix
string infixToPostfix(string infix) {
    Stack s;                     // Create dynamic stack
    string postfix = "";         // Store the answer

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];      // Read current character

        if (ch == ' ') {
            continue;            // Ignore spaces
        }

        // Add operands directly to postfix
        if (isalnum(static_cast<unsigned char>(ch))) {
            postfix += ch;
        }
        // Push opening parenthesis
        else if (ch == '(') {
            s.push(ch);
        }
        // Pop operators until matching opening parenthesis
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }

            if (s.isEmpty()) {
                return "Invalid Expression";  // No matching '('
            }

            s.pop();               // Remove '('
        }
        // Process operators
        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/' || ch == '^') {

            // Pop operators with higher or equal precedence.
            // For '^', equal precedence is not popped because it is right-associative.
            while (!s.isEmpty() && s.peek() != '(' &&
                   (precedence(s.peek()) > precedence(ch) ||
                   (precedence(s.peek()) == precedence(ch) && ch != '^'))) {
                postfix += s.pop();
            }

            s.push(ch);             // Push current operator
        }
        else {
            return "Invalid Expression";  // Unsupported character
        }
    }

    // Pop all remaining operators
    while (!s.isEmpty()) {
        if (s.peek() == '(') {
            return "Invalid Expression";  // Unmatched parenthesis
        }
        postfix += s.pop();
    }

    return postfix;                 // Return postfix expression
}

int main() {
    string infix;                   // Store infix expression

    cout << "Enter infix expression: ";
    getline(cin, infix);            // Read complete expression

    cout << "Postfix expression: "
         << infixToPostfix(infix) << endl;  // Display conversion

    return 0;                       // End program
}


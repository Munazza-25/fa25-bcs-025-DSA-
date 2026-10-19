
#include <iostream>  // For input and output
#include <string>    // For string
#include <cctype>    // For checking letters and digits
#include <cmath>     // For power function
using namespace std;

// Create a node for the dynamic stack
struct Node {
    double data;     // Store a numerical value
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

    void push(double value) {
        Node* temp = new Node;  // Create a new node
        temp->data = value;     // Store the number
        temp->next = top;       // Link it to the old top
        top = temp;             // Update the top pointer
    }

    double pop() {
        if (isEmpty()) {
            return 0;            // Return zero if stack is empty
        }

        Node* temp = top;        // Save the top node
        double value = temp->data; // Save its number
        top = top->next;         // Move top to next node
        delete temp;             // Delete the old top node
        return value;            // Return the removed number
    }
};

// Store values of variables A to Z
double variableValues[26];

// Store which variables have been entered
bool valueEntered[26] = {false};

// Evaluate the postfix expression
bool evaluatePostfix(string postfix, double& result) {
    Stack s;                     // Create a dynamic stack

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];    // Read current character

        if (ch == ' ') {
            continue;            // Ignore spaces
        }

        // Process numerical digits
        if (isdigit(static_cast<unsigned char>(ch))) {
            s.push(ch - '0');    // Convert character to number
        }
        // Process alphabetic variables
        else if (isalpha(static_cast<unsigned char>(ch))) {
            int index = toupper(static_cast<unsigned char>(ch)) - 'A';

            // Ask for a variable value only once
            if (!valueEntered[index]) {
                cout << "Enter value of "
                     << static_cast<char>('A' + index) << ": ";
                cin >> variableValues[index];
                valueEntered[index] = true;
            }

            s.push(variableValues[index]);  // Push variable value
        }
        // Process arithmetic operators
        else if (ch == '+' || ch == '-' ||
                 ch == '*' || ch == '/' || ch == '^') {

            if (s.isEmpty()) {
                return false;    // Not enough operands
            }

            double right = s.pop();  // Second operand

            if (s.isEmpty()) {
                return false;    // First operand is missing
            }

            double left = s.pop();   // First operand
            double answer = 0;       // Store operation result

            if (ch == '+') {
                answer = left + right;
            }
            else if (ch == '-') {
                answer = left - right;
            }
            else if (ch == '*') {
                answer = left * right;
            }
            else if (ch == '/') {
                if (right == 0) {
                    cout << "Error: Division by zero." << endl;
                    return false;
                }
                answer = left / right;
            }
            else if (ch == '^') {
                answer = pow(left, right);
            }

            s.push(answer);       // Push the calculated result
        }
        else {
            return false;         // Reject unsupported characters
        }
    }

    // A valid expression must leave exactly one value
    if (s.isEmpty()) {
        return false;
    }

    result = s.pop();             // Get the final answer

    if (!s.isEmpty()) {
        return false;             // Extra operands remain
    }

    return true;                  // Evaluation was successful
}

int main() {
    string postfix;               // Store postfix expression
    double result = 0;            // Store final result

    cout << "Enter postfix expression: ";
    getline(cin, postfix);        // Read the expression

    if (evaluatePostfix(postfix, result)) {
        cout << "Result: " << result << endl;
    }
    else {
        cout << "Invalid postfix expression." << endl;
    }

    return 0;                     // End program
}


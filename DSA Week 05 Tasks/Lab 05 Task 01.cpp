
#include <iostream>  // For input and output
#include <string>    // For string
using namespace std;

// Create a stack using an array
class Stack {
private:
    char arr[100];  // Store opening brackets
    int top;        // Index of the top element

public:
    Stack() {
        top = -1;   // -1 means the stack is empty
    }

    bool isEmpty() {
        return top == -1;  // Check whether stack is empty
    }

    void push(char value) {
        if (top < 99) {
            arr[++top] = value;  // Add bracket to stack
        }
    }

    char pop() {
        if (isEmpty()) {
            return '\0';  // Return empty character if no item exists
        }
        return arr[top--];  // Remove and return top bracket
    }
};

// Check whether the brackets are balanced
bool isBalanced(string expression) {
    Stack s;  // Create a stack

    for (int i = 0; i < expression.length(); i++) {
        char ch = expression[i];  // Read current character

        // Push opening brackets onto the stack
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        // Process closing brackets
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.isEmpty()) {
                return false;  // No opening bracket to match
            }

            char opening = s.pop();  // Get the latest opening bracket

            // Check whether both brackets match
            if ((ch == ')' && opening != '(') ||
                (ch == ']' && opening != '[') ||
                (ch == '}' && opening != '{')) {
                return false;
            }
        }
    }

    return s.isEmpty();  // No unmatched opening brackets should remain
}

int main() {
    string expression;  // Store the user's expression

    cout << "Enter an expression: ";
    getline(cin, expression);  // Read the complete expression

    if (isBalanced(expression)) {
        cout << "Balanced" << endl;  // Display result
    } else {
        cout << "Not Balanced" << endl;  // Display result
    }

    return 0;  // End program
}


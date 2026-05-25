#include <iostream>
#define MAX 20
using namespace std;

class InfixtoPostfix {
private:
    char stack[MAX];
    int top;

public:
    InfixtoPostfix() {
        top = -1;
    }

    void push(char c) {
        stack[++top] = c;
    }

    char pop() {
        return stack[top--];
    }

    char peek() {
        return stack[top];
    }

    bool Empty() {
        return top == -1;
    }

    int precedence(char op) {
        if (op == '$') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return 0;
    }

    bool isOperand(char c) {
        return ((c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z') ||
                (c >= '0' && c <= '9'));
    }

    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$');
    }

    string convert(string infix) {
        string postfix = "";

        for (int i = 0; i < infix.length(); i++) {
            char c = infix[i];

            if (isOperand(c)) {
                postfix += c;
            }
            else if (c == '(') {
                push(c);
            }
            else if (c == ')') {
                while (!Empty() && peek() != '(') {
                    postfix += pop();
                }
                pop(); // remove '('
            }
            else if (isOperator(c)) {
                // Special handling for right associative $
                while (!Empty() &&
                       ((precedence(peek()) > precedence(c)) ||
                        (precedence(peek()) == precedence(c) && c != '$'))) {
                    postfix += pop();
                }
                push(c);
            }
        }

        while (!Empty()) {
            postfix += pop();
        }

        return postfix;
    }
};

int main() {
    InfixtoPostfix ip;
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix expression: " << ip.convert(infix) << endl;
    return 0;
}

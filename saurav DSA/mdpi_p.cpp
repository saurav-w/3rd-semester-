#include<iostream>
#include<cmath>
#include<cstring>
#include<cctype>
#define MAX 100
using namespace std;

class Stack {
private:
    char stack[MAX];
    int top;

public:
    Stack() { top = -1; }

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
};

int precedence(char op) {
    if(op == '$') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

bool IsOperand(char c) {
    return isalnum(c);
}

bool IsOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='$');
}

bool IsDigit(char c) {
    return (c >= '0' && c <= '9');
}

void InfixtoPostfix(string infix) {
    Stack s;
    string postfix = "";

    for(char c : infix) {
        if(IsOperand(c))
            postfix += c;

        else if(c == '(')
            s.push(c);

        else if(c == ')') {
            while(!s.Empty() && s.peek() != '(')
                postfix += s.pop();
            s.pop();
        }

        else if(IsOperator(c)) {
            while(!s.Empty() && precedence(s.peek()) >= precedence(c))
                postfix += s.pop();
            s.push(c);
        }
    }

    while(!s.Empty())
        postfix += s.pop();

    cout << "Postfix Expression: " << postfix << endl;
}

string reverseExp(string exp) {
    int n = exp.length();
    for(int i=0; i<n/2; i++)
        swap(exp[i], exp[n-i-1]);
    return exp;
}

void InfixtoPrefix(string infix) {
    infix = reverseExp(infix);

    for(char &c : infix) {
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }

    Stack s;
    string prefix = "";

    for(char c : infix) {
        if(IsOperand(c))
            prefix += c;

        else if(c == '(')
            s.push(c);

        else if(c == ')') {
            while(!s.Empty() && s.peek() != '(')
                prefix += s.pop();
            s.pop();
        }

        else {
            while(!s.Empty() && precedence(s.peek()) > precedence(c))
                prefix += s.pop();
            s.push(c);
        }
    }

    while(!s.Empty())
        prefix += s.pop();

    prefix = reverseExp(prefix);
    cout << "Prefix Expression: " << prefix << endl;
}

int evalPostfix(string exp) {
    int s[MAX], top = -1;

    for(char c : exp) {
        if(IsDigit(c))
            s[++top] = c - '0';
        else {
            int a = s[top--];
            int b = s[top--];
            switch(c) {
                case '+': s[++top] = b + a; break;
                case '-': s[++top] = b - a; break;
                case '*': s[++top] = b * a; break;
                case '/': s[++top] = b / a; break;
                case '$': s[++top] = pow(b, a);
            }
        }
    }
    return s[top];
}

int evalPrefix(string exp) {
    int s[MAX], top = -1;

    for(int i = exp.length()-1; i >= 0; i--) {
        char c = exp[i];
        if(IsDigit(c))
            s[++top] = c - '0';
        else {
            int a = s[top--];
            int b = s[top--];
            switch(c) {
                case '+': s[++top] = a + b; break;
                case '-': s[++top] = a - b; break;
                case '*': s[++top] = a * b; break;
                case '/': s[++top] = a / b; break;
                case '$': s[++top] = pow(a, b);
            }
        }
    }
    return s[top];
}

int main() {
    int choice;
    string exp;

    do {
        cout << "\n----Menu----";
        cout << "\n1. Infix to Postfix";
        cout << "\n2. Infix to Prefix";
        cout << "\n3. Evaluation of Postfix";
        cout << "\n4. Evaluation of Prefix";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Infix Expression: ";
                cin >> exp;
                InfixtoPostfix(exp);
                break;

            case 2:
                cout << "Enter Infix Expression: ";
                cin >> exp;
                InfixtoPrefix(exp);
                break;

            case 3:
                cout << "Enter Postfix Expression(Digits only): ";
                cin >> exp;
                cout << "Result: " << evalPostfix(exp) << endl;
                break;

            case 4:
                cout << "Enter Prefix Expression(Digits only): ";
                cin >> exp;
                cout << "Result: " << evalPrefix(exp) << endl;
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while(choice != 5);

    return 0;
}

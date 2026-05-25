  #include <iostream>
using namespace std;

/* FACTORIAL */
int factorial(int n, int level = 0) {
    for (int i = 0; i < level; i++) cout << "\t";  // Indent per recursion depth
    if (n == 1 || n == 0) {
        cout << "1" << endl;
        return 1;
    }
    cout << n << " * factorial(" << n - 1 << ")" << endl;
    return n * factorial(n - 1, level + 1);
}

/* FIBONACCI */
int fibonacci(int n, int level = 0) {
    for (int i = 0; i < level; i++) cout << "\t";
    if (n == 0) {
        cout << "fib(0) = 0" << endl;
        return 0;
    }
    if (n == 1) {
        cout << "fib(1) = 1" << endl;
        return 1;
    }

    cout << "fib(" << n << ") = fib(" << n - 1 << ") + fib(" << n - 2 << ")" << endl;
    return fibonacci(n - 1, level + 1) + fibonacci(n - 2, level + 1);
}

/* GCD */
int gcd(int a, int b, int level = 0) {
    for (int i = 0; i < level; i++) cout << "\t";
    if (b == 0) {
        cout << "GCD = " << a << endl;
        return a;
    }
    cout << a << " % " << b << " = " << a % b << endl;
    return gcd(b, a % b, level + 1);
}

int main() {
    int choice;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Factorial\n";
        cout << "2. Fibonacci\n";
        cout << "3. GCD\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int n;
            cout << "Enter number: ";
            cin >> n;
            cout << "\nSteps:\n";
            int result = factorial(n);
            cout << "\nFinal Answer: " << n << "! = " << result << endl;
        }

        else if (choice == 2) {
            int n;
            cout << "Enter term number: ";
            cin >> n;
            cout << "\nSteps:\n";
            int result = fibonacci(n);
            cout << "\nFinal Answer: fib(" << n << ") = " << result << endl;
        }

        else if (choice == 3) {
            int a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "\nSteps:\n";
            int result = gcd(a, b);
            cout << "\nFinal Answer: GCD = " << result << endl;
        }

        else if (choice == 4) {
            cout << "Program exited.\n";
        }

        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}


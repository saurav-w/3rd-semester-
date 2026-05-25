#include <iostream>
using namespace std;

// Recursive function to solve Tower of Hanoi with step numbering
void towerOfHanoi(int n, char source, char auxiliary, char destination, int &step) {
    if (n == 1) {
        step++;  // increment step counter
        cout << step << ". Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, destination, auxiliary, step);

    // Move nth disk from source to destination
    step++;
    cout << step << ". Move disk " << n << " from " << source << " to " << destination << endl;

    // Move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, source, destination, step);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    int step = 0; // initialize step counter

    cout << "\nSteps to solve Tower of Hanoi for " << n << " disks:\n\n";
    towerOfHanoi(n, 'S', 'T', 'D', step);

    cout << "\nWhere:\n\tS = Source\n\tT = Temporary\n\tD = Destination" << endl;

    return 0;
}


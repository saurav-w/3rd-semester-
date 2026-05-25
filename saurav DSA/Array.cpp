#include <iostream>
#define MAX 10
using namespace std;

int main() {
    int choice, a[MAX], count = -1;
    

    do {
        cout<<"menu"<<endl;
        cout << "1. Enter in the array."<<endl;
        cout << "2. Display elements of the array."<<endl;
        cout << "3. Update element of the array using position."<<endl;
        cout << "4. Delete element of the array using position."<<endl;
        cout << "5. Search element in the array."<<endl;
        cout << "6. Maximum value in the array."<<endl;
        cout << "7. Minimum value in the array."<<endl;
        cout << "8. Exit"<<endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                if (count >= MAX - 1) {
                    cout << "Maximum capacity reached\n";
                    break;
                }
                int num;
                cout << "Enter element:\n";
                cin >> num;
                count++;
                a[count] = num;
                break;
            }

            case 2: {
                if (count < 0) {
                    cout << "Array is empty\n";
                    break;
                }
                for (int i = 0; i <= count; i++) {
                    cout << a[i] << " ";
                }
                cout << endl;
                break;
            }

            case 3: {
                if (count < 0) {
                    cout << "Array is empty\n";
                    break;
                }
                int pos, val;
                cout << "Enter position to update (0 to " << count << "):\n";
                cin >> pos;
                if (pos < 0 || pos > count) {
                    cout << "Invalid position\n";
                    break;
                }
                cout << "Enter new value:\n";
                cin >> val;
                a[pos] = val;
                break;
            }

            case 4: {
                if (count < 0) {
                    cout << "Array is empty\n";
                    break;
                }
                int pos;
                cout << "Enter position to delete (0 to " << count << "):\n";
                cin >> pos;
                if (pos < 0 || pos > count) {
                    cout << "Invalid position\n";
                    break;
                }
                for (int i = pos; i < count; i++) {
                    a[i] = a[i + 1];
                }
                count--;
                break;
            }

            case 5: {
                if (count < 0) {
                    cout << "Array is empty\n";
                    break;
                }
                int key;
                cout << "Enter element to search:\n";
                cin >> key;
                int found = -1;
                for (int i = 0; i <= count; i++) {
                    if (a[i] == key) {
                        found = i;
                        break;
                    }
                }
                if (found != -1) cout << "Element found at position " << found << endl;
                else cout << "Element not found\n";
                break;
            }

            case 6: {
                if (count < 0) {
                    cout << "Array is empty\n";
                    break;
                }
                int max = a[0];
                for (int i = 1; i <= count; i++) {
                    if (a[i] > max) max = a[i];
                }
                cout << "Maximum value: " << max << endl;
                break;
            }

            case 7: {
                if (count < 0) {
                    cout << "Array is empty\n";
                    break;
                }
                int min = a[0];
                for (int i = 1; i <= count; i++) {
                    if (a[i] < min) min = a[i];
                }
                cout << "Minimum value: " << min << endl;
                break;
            }

            case 8:
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 8);

    return 0;
}

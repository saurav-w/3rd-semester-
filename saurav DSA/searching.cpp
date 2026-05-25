#include <iostream>
using namespace std;

int main() {
    int arr[100], n, key, choice;
    int low, high, mid, i;
    int found;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:";
    for(i = 0; i < n; i++){
        cin >> arr[i];
    }

    do {
        cout << "\n--- Searching Menu ---\n";
        cout << "1. Sequential Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){

        case 1:
            cout << "Enter element to search: ";
            cin >> key;
            found = 0;

            for(i = 0; i < n; i++){
                if(arr[i] == key){
                    cout << "Element found at position " << i + 1 << endl;
                    found = 1;
                    break;
                }
            }

            if(found == 0)
                cout << "Element not found\n";

            break;

        case 2:
            cout << "Enter element to search: ";
            cin >> key;

            low = 0;
            high = n - 1;
            found = 0;

            while(low <= high){
                mid = (low + high) / 2;

                if(arr[mid] == key){
                    cout << "Element found at position " << mid + 1 << endl;
                    found = 1;
                    break;
                }
                else if(arr[mid] < key)
                    low = mid + 1;
                else
                    high = mid - 1;
            }

            if(found == 0)
                cout << "Element not found\n";

            break;

        case 3:
            cout << "Program Exit.\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while(choice != 3);

    return 0;
}

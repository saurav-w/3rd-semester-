  #include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() { head = NULL; }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at the beginning.\n";
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << value << " inserted at the end.\n";
    }

    // Insert at specific position (1-based index)
    void insertAtPosition(int value, int pos) {
        if (pos <= 0) {
            cout << "Invalid position!\n";
            return;
        }

        if (pos == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;
        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Position out of range!\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        cout << value << " inserted at position " << pos << ".\n";
    }

    // Delete first node
    void deleteFirst() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from the beginning.\n";
        delete temp;
    }

    // Delete last node
    void deleteLast() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if (head->next == NULL) {
            cout << head->data << " deleted from the list.\n";
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;

        cout << temp->next->data << " deleted from the end.\n";
        delete temp->next;
        temp->next = NULL;
    }

    // Delete node at specific position
    void deleteAtPosition(int pos) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        if (pos <= 0) {
            cout << "Invalid position!\n";
            return;
        }

        if (pos == 1) {
            deleteFirst();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "Position out of range!\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;
        cout << del->data << " deleted from position " << pos << ".\n";
        delete del;
    }

    // Display the list
    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, value, pos;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at specific position\n";
        cout << "4. Delete first node\n";
        cout << "5. Delete last node\n";
        cout << "6. Delete at specific position\n";
        cout << "7. Display list\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                list.insertAtEnd(value);
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                list.insertAtPosition(value, pos);
                break;

            case 4:
                list.deleteFirst();
                break;

            case 5:
                list.deleteLast();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos;
                list.deleteAtPosition(pos);
                break;

            case 7:
                list.display();
                break;

            case 8:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}


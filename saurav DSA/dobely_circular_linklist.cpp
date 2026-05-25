#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value){
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class DoublyCircularLinkedList{
public:
    Node* head;

    DoublyCircularLinkedList(){
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int value){
        Node* newNode = new Node(value);

        if(head == NULL){
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        }
        else{
            Node* last = head->prev;

            newNode->next = head;
            newNode->prev = last;
            head->prev = newNode;
            last->next = newNode;
            head = newNode;
        }
    }

    // Insert at end
    void insertAtEnd(int value){
        if(head == NULL){
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }

    // Insert at specific position
    void insertAtPos(int value, int pos){
        if(pos == 1){
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;
        int i = 1;

        while(i != pos-1 && temp->next != head){
            temp = temp->next;
            i++;
        }

        if(temp->next == head && i != pos-1){
            cout<<"Invalid position!"<<endl;
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // Delete from beginning
    void deleteFromBeginning(){
        if(head == NULL){
            cout<<"List is empty!"<<endl;
            return;
        }

        if(head->next == head){
            cout<<"Deleted: "<<head->data<<endl;
            delete head;
            head = NULL;
            return;
        }

        Node* last = head->prev;
        Node* temp = head;

        head = head->next;
        head->prev = last;
        last->next = head;

        cout<<"Deleted: "<<temp->data<<endl;
        delete temp;
    }

    // Delete from end
    void deleteFromEnd(){
        if(head == NULL){
            cout<<"List is empty!"<<endl;
            return;
        }

        if(head->next == head){
            cout<<"Deleted: "<<head->data<<endl;
            delete head;
            head = NULL;
            return;
        }

        Node* last = head->prev;
        Node* secondLast = last->prev;

        secondLast->next = head;
        head->prev = secondLast;

        cout<<"Deleted: "<<last->data<<endl;
        delete last;
    }

    // Delete from specific position
    void deleteFromPos(int pos){
        if(pos == 1){
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        int i = 1;

        while(i != pos && temp->next != head){
            temp = temp->next;
            i++;
        }

        if(temp->next == head && i != pos){
            cout<<"Invalid position!"<<endl;
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        cout<<"Deleted: "<<temp->data<<endl;
        delete temp;
    }

    // Traverse forward
    void traverseForward(){
        if(head == NULL){
            cout<<"List is empty!"<<endl;
            return;
        }

        Node* temp = head;
        cout<<"Forward: ";
        do{
            cout<<temp->data<<" <-> ";
            temp = temp->next;
        }while(temp != head);
        cout<<"(HEAD)"<<endl;
    }

    // Traverse backward
    void traverseBackward(){
        if(head == NULL){
            cout<<"List is empty!"<<endl;
            return;
        }

        Node* temp = head->prev;
        cout<<"Backward: ";
        do{
            cout<<temp->data<<" <-> ";
            temp = temp->prev;
        }while(temp != head->prev);
        cout<<"(HEAD)"<<endl;
    }
};

int main(){
    DoublyCircularLinkedList dl;
    int choice,value,pos;

    do{
        cout<<"--- DOUBLY CIRCULAR LINKED LIST MENU ---"<<endl;
        cout<<"1. Insert at beginning"<<endl;
        cout<<"2. Insert at end"<<endl;
        cout<<"3. Insert at position"<<endl;
        cout<<"4. Delete from beginning"<<endl;
        cout<<"5. Delete from end"<<endl;
        cout<<"6. Delete from position"<<endl;
        cout<<"7. Traverse forward"<<endl;
        cout<<"8. Traverse backward"<<endl;
        cout<<"9. Exit"<<endl;

        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value: ";
                cin>>value;
                dl.insertAtBeginning(value);
                break;

            case 2:
                cout<<"Enter value: ";
                cin>>value;
                dl.insertAtEnd(value);
                break;

            case 3:
                cout<<"Enter value: ";
                cin>>value;
                cout<<"Enter position: ";
                cin>>pos;
                dl.insertAtPos(value,pos);
                break;

            case 4:
                dl.deleteFromBeginning();
                break;

            case 5:
                dl.deleteFromEnd();
                break;

            case 6:
                cout<<"Enter position: ";
                cin>>pos;
                dl.deleteFromPos(pos);
                break;

            case 7:
                dl.traverseForward();
                break;

            case 8:
                dl.traverseBackward();
                break;

            case 9:
                cout<<"Exiting..."<<endl;
                break;

            default:
                cout<<"Invalid choice!"<<endl;
        }

    }while(choice != 9);

    return 0;
}

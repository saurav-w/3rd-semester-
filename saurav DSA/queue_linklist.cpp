#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int value){
			data=value;
			next=NULL;
		}
};

class Queue{
	Node* front;
	Node* rear;
	
	public:
		Queue(){
			front=NULL;
			rear=NULL;
		}
		
		void enqueue(int value){
			Node* newNode=new Node(value);
			if(newNode==NULL){
				cout<<"Queue Overflow!"<<endl;
		        return;
			}
			if(front==NULL){
				front=rear=newNode;
			}
			else{
				rear->next=newNode;
				rear=newNode;
			}
			cout<<"Enqueued: "<<value<<endl;
		}
		
		void dequeue(){
			if(front==NULL){
				cout<<"Queue Underflow!"<<endl;
				return;
			}
			Node* temp = front;
        cout<<"Dequeued: "<<front->data<<endl;

        front = front->next;

        if(front == NULL)
            rear = NULL;

        delete temp;
		}
		
		void display(){
        if(front == NULL){
            cout<<"Queue is empty!"<<endl;
            return;
        }

        Node* temp = front;
        cout<<"Queue elements: ";
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};


int main(){
    Queue q;
    int choice,value;

    do{
        cout<<"--- QUEUE USING LINKED LIST MENU ---"<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;

        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value: ";
                cin>>value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                cout<<"Exiting..."<<endl;
                break;

            default:
                cout<<"Invalid choice!"<<endl;
        }

    }while(choice != 4);

    return 0;
}

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

class Stack{
	Node* top;
	
	public:
		Stack(){
			top=NULL;
		}
		
		void push(int value){
			Node* newNode= new Node(value);
			if(newNode==NULL){
				cout<<"Stack Overflow!"<<endl;
				
			}else{
				newNode->next=top;
				top=newNode;
				cout<<"Pushed: "<<value<<endl;
			}
		}
		
		void pop(){
			if(top==NULL){
				cout<<"Stack Underflow!"<<endl;
				return;
			}
			else{
				Node* temp=top;
				cout<<"Popped: "<<top->data<<endl;
				top=top->next;
				delete temp;
			}
		}
		
		void peek(){
			if(top==NULL){
				cout<<"Stack is empty!"<<endl;
				return;
			}
			cout<<"Top element: "<<top->data<<endl;
		}
		
		void display(){
			if(top==NULL){
				cout<<"Stack is empty!"<<endl;
				return;
			}else{
				Node*temp=top;
				cout<<"Stack elements: ";
				while(temp!=NULL){
					cout<<temp->data<<"->";
					temp=temp->next;
				}
				cout<<"NULL"<<endl;
			}
		}
};

int main(){
	Stack s;
	int choice, value;
	
	do{
		cout<<"------STACK USING LINKED LIST MENU--------------"<<endl;
		cout<<"1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"3. Peek/Top"<<endl;
		cout<<"4. Traverse"<<endl;
		cout<<"5. Exit"<<endl;
		
		cout<<"Enter chocie: ";
		cin>>choice;
		
		switch(choice){
			   case 1:
                cout<<"Enter value: ";
                cin>>value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                s.display();
                break;

            case 5:
                cout<<"Exiting..."<<endl;
                break;

            default:
                cout<<"Invalid choice!"<<endl;
        }

    }while(choice != 5);

    return 0;
}

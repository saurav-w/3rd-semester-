#include<iostream>
#define MAX 6
using namespace std;

class Stack {
	private:
		int stack[MAX];
		int top;
		
	public:
		void makeEmptyStack() {
			top = -1;
		}
		
		bool Overflow() {
			if(top == MAX-1) {
				return true;
			}
			else return false;
		}
		
		bool Underflow() {
			if(top < 0) {
				return true;
			}
			else return false;
		}
		
		void Push(int x) {
			if(Overflow()) {
				cout<<"Stack is full.\n";
			}
			else {
				top++;
				stack[top] = x;
				cout<<x<<" is pushed."<<endl;
			}
		}
		
		void Pop() {
			if(Underflow()) {
				cout<<"Stack is empty.\n";
			}
			else {
				int temp = stack[top];
				cout<<temp<<" is popped."<<endl;
				top = top - 1;
			}
		}
		
		void Traverse() {
			if(Underflow()) {
				cout<<"Stack is empty.\n";
			}
			else {
				for(int i=top; i>=0; i--) {
					cout<<stack[i]<<" ";
				}
			}
		}
		
		int Top() {
			if(Underflow()) {
				cout<<"Stack is empty.\n";
			}
			else {
				return stack[top];
			}
		}
};

int main() {
	Stack s;
	s.makeEmptyStack();
	int choice, value;
	
	do {
		cout<<"\n------Menu------\n";
		cout<<"1. Make stack empty.\n";
		cout<<"2. Push the data into stack.\n";
		cout<<"3. Pop the data from stack.\n";
		cout<<"4. Traverse the data.\n";
		cout<<"5. Peek/Top in stack.\n";
		cout<<"6. Exit.\n";
		
		cout<<"Enter your choice: "<<endl;
		cin>>choice;
		
		switch(choice) {
			case 1:
				s.makeEmptyStack();
				break;
				
			case 2:
				cout<<"Enter the value: "<<endl;
				cin>>value;
				s.Push(value);
				
				break;
				
			case 3:
				s.Pop();
				break;
				
			case 4:
				s.Traverse();
				break;
				
			case 5:
				cout<<"Top element is "<<s.Top();
				break;
				
			case 6:
				cout<<"Exiting."<<endl;
				break;
				
			default:
				cout<<"Invalid choice."<<endl;
		}
	} while(choice != 6);
	return 0;
}
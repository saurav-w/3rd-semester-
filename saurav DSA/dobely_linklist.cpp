#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* prev;
		Node* next;
		
		Node(int value){
			data=value;
			prev=NULL;
			next=NULL;
		}
};

class DoublyLinkedlist{
	public:
		Node *head;
		
		DoublyLinkedlist(){
			head=NULL;
		}
		//Insert at beginning
		void insertAtBeginning(int value){
			Node *newNode = new Node(value);
			if(head==NULL){
				head=newNode;
			}
			else {
               newNode->next=head;
               head->prev=newNode;
               head=newNode;
        }
		}
		
		void insertAtEnd(int value){
			Node* newNode= new Node(value);
			if(head==NULL){
				head=newNode;	
			}
			else{
				Node* temp=head;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=newNode;
				newNode->prev=temp;
			}
		}
		
		void insertAtPos(int value,int pos){
   			 if(pos==1){
        		insertAtBeginning(value);
        		return;
   			 }

   			 Node* newNode = new Node(value);
   			 Node* temp = head;
   			 int i=1;

    		while(i!=pos-1 && temp!=NULL){
       		 temp=temp->next;
       		 i++;
   			 }

    		if(temp==NULL){
        		cout<<"Invalid position!"<<endl;
       		    return;
   			 }

   			 newNode->next = temp->next;
   			 newNode->prev=temp;
   			 if(temp->next!=NULL){
   			 	temp->next->prev=newNode;
				}
				temp->next=newNode;
			}

		
		void deleteFromBeginning(){
		 if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

		Node* temp=head;
		head=head->next;
		
        if (head!=NULL) {
        	head->prev=NULL;
            cout <<" Deleted:" << temp->data<<endl;
            delete temp;
        }
		}
		
    	void deleteFromEnd(){
    			if(head==NULL){
       			 cout<<"Cannot delete. The list is empty!"<<endl;
   				 }
    			else if(head->next==NULL){
       				 cout<<"Deleted data: "<<head->data<<endl;
        			delete head;
                    head=NULL;
   				 }
   				 else{
                 Node* temp = head;
                  while(temp->next!=NULL){
           			 temp = temp->next;
       				 }
      			  cout<<"Deleted data: "<<temp->data<<endl;
                   temp->prev->next=NULL;
                   delete (temp);
  		  }
		}

		
		void deleteFromPos(int pos){
    		if(head == NULL){
        cout << "List is empty!" << endl;
        return;
    }

    if(pos==1){
        deleteFromBeginning();
        return;
    }

    Node* temp=head;
    int i=1;

    while(i!=pos && temp != NULL){
        temp = temp->next;
        i++;
    }

    if(temp == NULL){
        cout<<"Invalid position!"<<endl;
        return;
    }

    // Update links
    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    cout<<"Deleted element from position "<<pos<<" : "<<temp->data<<endl;
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
        while(temp != NULL){
            cout<<temp->data<<" <-> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    // Traverse backward
    void traverseBackward(){
        if(head == NULL){
            cout<<"List is empty!"<<endl;
            return;
        }

        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }

        cout<<"Backward: ";
        while(temp != NULL){
            cout<<temp->data<<" <-> ";
            temp = temp->prev;
        }
        cout<<"NULL"<<endl;
    }
};


int main(){
	DoublyLinkedlist li;
	int choice,value,pos;
	do{
		cout<<"--------Doubly Linked List Menu-------------\n"<<endl;
		cout<<"1. Insert at Beginning."<<endl;
		cout<<"2. Insert at end."<<endl;
		cout<<"3. Insert at specific position."<<endl;
		cout<<"4. Delete from beginning."<<endl;
		cout<<"5. Delete from end."<<endl;
		cout<<"6. Delete from specific postion."<<endl;
		cout<<"7. Traverse Forward."<<endl;
		cout<<"8. Traverse Backward."<<endl;
		cout<<"9. Exit."<<endl;
		
		cout<<"Enter your choice: ";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Enter the value to insert at start: ";
				cin>>value;
				li.insertAtBeginning(value);
				cout<<value<<" is inserted at beginnning."<<endl;
				break;
				
			case 2:
				cout<<"Enter the value to insert at end: ";
				cin>>value;
				li.insertAtEnd(value);
				cout<<value<<" is inserted at the end."<<endl;
				break;
				
			case 3:
				cout<<"Enter the value to insert: ";
				cin>>value;
				cout<<"Enter the position to insert the value: ";
				cin>>pos;
				li.insertAtPos(value,pos);
				cout<<value<<" is inserted at "<< pos <<endl;
				break;
				
			case 4:
				li.deleteFromBeginning();
				break;
				
			case 5:
				li.deleteFromEnd();
				break;
				
			case 6:
				cout<<"Enter the position to delete: ";
				cin>>pos;
				li.deleteFromPos(pos);
				break;
			case 7:
				li.traverseForward();
				break;
			
			case 8:
				li.traverseBackward();
				break;
				
			case 9:
				cout<<"Exiting..."<<endl;
				break;
				
			default:
				cout<<"Invalid choice.Please enter a valid choice."<<endl;
		}
	}while(choice!=9);
return 0;
}

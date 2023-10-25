#include <iostream >
using namespace std;

class node{
	public:
	int data;
	node* next;
	node(int data){
		this -> data = data;
		this -> next = NULL;
	}
	 ~node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};


void insertathead(node* &head, node* &tail,  int d){
	    if(head == NULL) {
	        node* temp = new node(d);
	        head = temp;
	        tail = temp;
	    }
	    else{
	        node* temp = new node(d);
	        temp -> next = head;
	        head = temp;
	    }
}


		
void deleteNode(int position, node* & head) { 
     if (head == NULL) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
    
    if(position == 1) {
        node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    
   
}

void print(node* &head){
	node* temp = head;
	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}
int main() {
    node*head = NULL;
    node*tail = NULL;

    
    insertathead(head, tail, 3);
    insertathead(head, tail, 2);
    insertathead(head, tail, 1);

    cout << "Linked List after insertions : " << endl;
    print(head);

    
    deleteNode(0, head);

    cout << "Linked List after deletion: " << endl;
    print(head);

    return 0;
}










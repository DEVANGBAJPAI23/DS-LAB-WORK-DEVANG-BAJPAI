#include <iostream >
using namespace std;
//Implement singly link list insertion deletion at start and end
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
        cout << " memory is free for node with data " << value << endl;
    }
};


void insertathead(node* &head, int d){
	node* temp = new node(d);
	temp -> next = head;
	head = temp;
}

void insertattail(node* &tail, int d) {
     // new node create
    node* temp = new node(d);
    tail -> next = temp;
    tail  = temp;
    
}
void insertatpos(node* &head, node* &tail, int pos, int d){
	if(pos == 1){
		insertathead(head, d);
	}
	else{
		node* temp = new node(d);
		int i = 1;
		node* dev = head;
		while(i < pos - 1 ){
			dev = dev -> next;
			i++;
			
		}
		if(dev -> next == NULL){
			insertattail(tail, d);
		}
		
		temp -> next = dev -> next;
		dev -> next = temp;
		
	}
}
void deleteNode(int position, node* & head) { 

    //deleting first or start node
    if(position == 1) {
        node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        node* curr = head;
        node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

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



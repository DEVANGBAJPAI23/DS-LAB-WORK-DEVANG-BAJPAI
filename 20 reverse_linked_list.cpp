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
};
void insert_at_head(node* &head, node* &tail, int d){
	if(head == NULL){
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
void insert_at_tail(node* &tail, node* &head, int d){
	if(tail == NULL){
		node*temp = new node(d);
		tail = temp;
		head = temp;
	}
	else{
		node*temp = new node(d);
		tail -> next = temp;
		
		tail = temp;
	}
}

void reversenode(node* &head){
	if(head == NULL || head -> next == NULL ){
		return ;
	}
	node*forward = NULL;
	node*curr = head;
	node*prev = NULL;
	
	while(curr != NULL){
		forward = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = forward;
	}
	head = prev;
}
void print(node* head){
	node* temp = head;
	
	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}
int main(){
	
	node*head = NULL;
	node*tail = NULL;
	
	insert_at_head(head, tail, 30);
	insert_at_head(head, tail, 40);
	insert_at_head(head, tail, 20);
	insert_at_head(head, tail, 10);
	insert_at_head(head, tail, 50);
	insert_at_tail(tail, head, 200);
    cout << "linked list is " << endl;
    print(head);
    cout << "reverse linked list is " << endl;
	reversenode(head);
	print(head);

}

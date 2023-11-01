#include <iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;
	node* prev;
	
	node(int d){
		this -> data = d;
		this -> next = NULL;
		this -> prev = NULL;
	}
	~node(){
		int value = this -> data;
		if( next != NULL){
			delete next;
			 next = NULL;
		}
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
		head -> prev = temp;
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
		temp -> prev = tail;
		tail = temp;
	}
}

void insert_at_pos(node* &head, node* &tail, int pos, int d){
	if(pos == 1){
		insert_at_head(head, tail, d);
	}
	else{
		node*temp = head;
		int cnt = 1;
		while(cnt < pos - 1){
			temp = temp -> next;
			cnt++;
		}
		if(temp -> next == NULL){
			insert_at_tail(tail, head, d);
		}
		node*dev = new node(d);
		dev -> next = temp -> next;
		dev -> prev = temp;
		temp -> next = dev;
		temp -> next -> prev = dev; 
		
	}
}
void deletenode(node* &head, int pos){
	if(pos == 1){
		node*temp = head;
		temp -> next -> prev = NULL; 
		head = head -> next;
		temp -> next = NULL;
		delete temp; 
	}
	else{
		node* curr = head;
		node*prev = NULL;
		int cnt = 1;
		while(cnt < pos){
			prev = curr;
			curr = curr -> next;
			cnt++;
		}
		curr -> prev = NULL;
		curr -> next -> prev = prev; 
		prev -> next = curr -> next;
		curr -> next = NULL;
		delete curr;  
	}
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
	insert_at_pos(head, tail, 3, 100);
	print(head);
	cout << "after deleting the node = " << endl;
	deletenode(head, 2);
	print(head);
	

}

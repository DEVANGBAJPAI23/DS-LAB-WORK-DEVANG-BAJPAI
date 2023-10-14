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
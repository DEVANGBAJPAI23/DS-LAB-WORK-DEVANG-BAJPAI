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
node* getmidnode(node* &head){
	node* fast = head ->  next;
	node* slow = head;

	while(fast != NULL && fast -> next != NULL ){
		fast = fast -> next -> next;
		
		slow = slow -> next;

	}
	return slow;
}
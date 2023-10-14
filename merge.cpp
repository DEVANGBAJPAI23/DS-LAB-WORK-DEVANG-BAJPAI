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

node* merge(node* &first, node* &second){
	if(first == NULL){
		return second;
	}
	if(second == NULL){
		return first;
	}
	node* ans = new node(-1);
	node* temp = ans;
	
	while((first != NULL) && (second != NULL)){
		if(first -> data <= second -> data){
			temp -> next = first;
			temp = first;
			first = first -> next;
		}
		else{
			temp -> next = second;
			temp = second;
			second = second -> next;
		}
	}
	while(first != NULL){
		temp -> next = first;
		temp = first;
		first = first -> next;
	}
	while(second != NULL){
		temp -> next = second;
		temp = second;
		second = second -> next;
	}
	ans = ans -> next;
	return ans;
}
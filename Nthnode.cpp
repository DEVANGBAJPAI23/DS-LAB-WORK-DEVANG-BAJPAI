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
node* KfromEnd(node* head,int N){
    node* slow=head;
    node* fast=head;
    while(N--){
        fast=fast->next;
    }
    if(fast==NULL)return head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    return slow->next;
}
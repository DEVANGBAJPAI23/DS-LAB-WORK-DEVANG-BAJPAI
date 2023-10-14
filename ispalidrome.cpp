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
bool isPalindrome(node* head) {
        node* temp=new node(head->data);
        node* temp2=head->next;
        node* orgh=temp;
        while(temp2!=NULL){
            temp->next=new node(temp2->data);
            temp2=temp2->next;
            temp=temp->next;
        }
        node* prev=NULL;
        node* curr=head;
        while(curr!=NULL){
            node* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        node* newHead=prev;
        cout<<endl;
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
        }
        cout<<endl;
        while(orgh!=NULL){
            
            if(orgh->data!=newHead->data){
                return false;
            }
            orgh=orgh->next;
            newHead=newHead->next;
        }
        return true;
    }
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


bool hascycle(node* head){
    if (head == NULL)  return false;

    node* fast = head;
    node * slow = head ;
    while(fast && fast -> next){
        if(fast == slow){
            return true;
        }
        slow = slow->next;
        fast= fast->next->next;
        
    }
    return false;
}
void removeCycle(node* head) {
    node* curr = head;
    node* temp = head;

    // Detect the start of the cycle
    while (true) {
        curr  = curr -> next;
        temp = temp -> next -> next;
        if (temp == curr) {
            break;
        }
    }
    node* finder = head;
    while (finder != curr) {
        finder = finder->next;
        curr = curr -> next;
    }

    // Break the cycle
    temp = curr;
    while (temp->next != curr) {
        temp = temp ->next;
    }
    temp ->next =NULL;
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
	
	node*head1 = new node(1);
    head1 -> next = new node(2);
    head1 -> next -> next = new node(3);
    head1 -> next -> next -> next = new node(4);
    head1 -> next -> next -> next -> next = new node(5);
    head1 -> next -> next -> next -> next -> next = head1 -> next -> next;
	if(hascycle(head1)){
        cout << "cycle is present" << endl;
        
        removeCycle(head1);
        cout << "Cycle removed." << endl;
    }
    else{
        cout << "cycle is not present" << endl;
    }
   

	
    return 0;
    
	

}

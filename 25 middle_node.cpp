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
		temp -> next = dev;
	}
}
node* getmidnode(node* &head){
	node* fast = head ->  next;
	node* slow = head;

	while(fast != NULL && fast -> next != NULL ){
		fast = fast -> next -> next;
		
		slow = slow -> next;

	}
	return slow;
}
int main(){
	
	node*head = NULL;
	node*tail = NULL;
	cout << "inserting the nodes" << endl;
	insert_at_head(head, tail, 30);
	insert_at_head(head, tail, 40);
	insert_at_head(head, tail, 20);
	insert_at_head(head, tail, 10);
	insert_at_head(head, tail, 50);
	insert_at_tail(tail, head, 200);
	insert_at_pos(head, tail, 3, 100);
	print(head);
	cout << "middle node is "<< getmidnode(head) -> data << endl;
	

}

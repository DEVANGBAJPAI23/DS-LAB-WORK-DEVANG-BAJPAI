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
int getlen(node* &head){
	int count = 0;
	node* curr = head;
	while(curr != NULL){
		curr = curr -> next;
		count++;
	}
	return count;
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

node* mergesort(node* &head){
	if(head == NULL || head ->next == NULL){
		return head;
	}
            
        
    	node* mid = getmidnode(head);
       node* first = head;
       node* second = mid -> next;
       mid -> next = NULL;
       
       first = mergesort(first);
       second = mergesort(second);
       return merge(first, second);
	
}
void print(node* &head){
	node* temp = head;
	while(temp != NULL){
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << endl;
}

int main(){
	node* node1 = new node(10);

	
	node* head = node1;
	node* tail = node1;
	insertattail(tail, 20);
	
	insertattail(tail, 30);
	insertatpos(head, tail, 2, 200);
	insertatpos(head, tail, 2, 1000);
	print(head);	
	cout << getmidnode(head) -> data << endl;
	cout << getlen(head) << endl;
	reversenode(head);
	print(head);
	head = mergesort(head);
	print(head);
	return 0;
	
	
	
}

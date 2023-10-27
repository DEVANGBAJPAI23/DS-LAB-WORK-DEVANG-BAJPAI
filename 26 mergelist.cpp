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
void displayList(node* head) {
    node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
  cout << "NULL" << std::endl;
}

int main() {
    
    node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

   cout << "List 1: ";
    displayList(list1);

   cout << "List 2: ";
    displayList(list2);

   
    node* mergedList = merge(list1, list2);

   cout << "Merged List: ";
    displayList(mergedList);

    return 0;
}

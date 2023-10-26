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


int length(node* &head){
	int count = 0;
	node* curr = head;
	while(curr != NULL){
		curr = curr -> next;
		count++;
	}
	return count;
}

node* findMergePoint(node* firstHead , node* secondHead) {
    int firstListLength = length(firstHead), secondListLength = length(secondHead);
    while (firstListLength > secondListLength)
    {
        firstHead = firstHead->next;
        firstListLength--;
    }

    while (firstListLength < secondListLength)
    {
        secondHead = secondHead->next;
        secondListLength--;
    }

    
    while (firstHead != secondHead)
    {
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }

    if (firstHead == NULL)
    {
        return  NULL;
    }
     return firstHead;
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
	
    cout << "linked list 1 is " << endl;
    print(head1);

	node * head2 = new node(6);
    head2 -> next = head1 -> next -> next;
    cout << "linked list 2 is " << endl;
    print(head2);

    node * mergePoint = findMergePoint(head1, head2);
    if (mergePoint) {
        cout << "Merge Point Value: " << mergePoint->data << endl;
    } else {
        cout << "No merge point found." << endl;
    }
    return 0;
    
	

}

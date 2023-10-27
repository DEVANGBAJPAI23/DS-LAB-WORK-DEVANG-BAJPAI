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
node* reverseLinkedList(node* head) {
    node* prev = nullptr;
    node* current = head;
    node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}


bool isPalindrome(node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true; 
    }

    
    node* slow = head;
    node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    
    slow = reverseLinkedList(slow);

   
    while (slow != nullptr) {
        if (head->data != slow->data) {
            return false; 
        }
        head = head->next;
        slow = slow->next;
    }

    return true; 
}
int main() {
    
    node* head = new node(11);
    head->next = new node(21);
    head->next->next = new node(31);
    head->next->next->next = new node(21);
    head->next->next->next->next = new node(11);

  cout << "Is the linked list a palindrome? " << (isPalindrome(head) ? "Yes" : "No") << endl;

    return 0;
}

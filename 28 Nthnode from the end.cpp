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
void KfromEnd(node* head,int n){
    if (head == nullptr || n <= 0) {
        cout << "Invalid input or empty list." << endl;
        return;
    }

    node* firstPointer = head;
    node* secondPointer = head;

    
    for (int i = 0; i < n; i++) {
        if (secondPointer == nullptr) {
            cout << "List is not long enough." << endl;
            return;
        }
        secondPointer = secondPointer->next;
    }

    
    while (secondPointer != nullptr) {
        firstPointer = firstPointer->next;
        secondPointer = secondPointer->next;
    }

   cout << "The " << n << "th node from the end is: " << firstPointer->data << std::endl;
}

void displayList(node* head) {
    node* current = head;
    while (current != nullptr) {
       cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}
int main() {
    // Create a sample linked list
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    cout << "Original Linked List: ";
    displayList(head);

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    KfromEnd(head, n);

    return 0;
}

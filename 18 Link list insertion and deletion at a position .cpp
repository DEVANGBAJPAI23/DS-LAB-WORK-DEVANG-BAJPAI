#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    
    void insertAtPosition(int value, int position) {
        Node* newNode = new Node(value);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            int currentPosition = 0;
            while (currentPosition < position - 1 && current->next != NULL) {
                current = current->next;
                currentPosition++;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    
    void deleteAtPosition(int position) {
        if (head == NULL) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } 
        else {
            Node* current = head;
            int currentPosition = 0;
            while (currentPosition < position - 1 && current->next !=NULL) {
                current = current->next;
                currentPosition++;
            }
            if (current->next == NULL) {
                cout << "Position not found in the list." << endl;
                return;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

   
    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << "  ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;
    myList.insertAtPosition(1, 0); 
    myList.insertAtPosition(2, 1); 
    myList.insertAtPosition(3, 1); 

    cout << "Linked List after insertions:" << endl;
    myList.display();

    
    myList.deleteAtPosition(1);

    cout << "Linked List after deletion:" << endl;
    myList.display();

    return 0;
}







   

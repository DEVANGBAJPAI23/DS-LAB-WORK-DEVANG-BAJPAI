#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
		Node(){
			this->data = 0;
			this->next = NULL;
		}
};

class Stack {
private:
    Node* top; 

public:
    Stack() {
        top = nullptr; 
    }

    
    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    
    bool isEmpty() {
        return top == nullptr;
    }

    
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1; 
        }
        return top->data;
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top of the stack: " << stack.peek() << endl;

    stack.pop();
    cout << "Top of the stack after pop: " << stack.peek() << endl;

    return 0;
}

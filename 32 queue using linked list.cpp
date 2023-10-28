#include <iostream>
using namespace std;


class Node {
	public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front; 
    Node* rear;  

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1; 
        }
        int dequeuedValue = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        return dequeuedValue;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to display the queue
    void display() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << std::endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

   cout << "Dequeued element: " << queue.dequeue() << endl;

    queue.enqueue(40);

   cout << "Queue contents: ";
    queue.display();

    return 0;
}

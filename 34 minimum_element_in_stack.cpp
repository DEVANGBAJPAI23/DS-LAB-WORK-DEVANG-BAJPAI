#include <iostream>
#include <stack>

class MinStack {
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;

public:
    // Push an element onto the stack
    void push(int value) {
        mainStack.push(value);

        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
    }

    // Pop the top element from the stack
    void pop() {
        if (mainStack.empty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return;
        }

        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }

        mainStack.pop();
    }

    // Get the top element of the stack
    int top() {
        if (mainStack.empty()) {
            std::cout << "Stack is empty. No top element." << std::endl;
            return -1; // You can choose to return a special value for an empty stack
        }
        return mainStack.top();
    }

    // Get the minimum element in the stack
    int getMin() {
        if (minStack.empty()) {
            std::cout << "Stack is empty. No minimum element." << std::endl;
            return -1; // You can choose to return a special value for an empty stack
        }
        return minStack.top();
    }
};

int main() {
    MinStack stack;

    stack.push(3);
    stack.push(5);
    stack.push(2);
    stack.push(1);

    std::cout << "Minimum element in the stack: " << stack.getMin() << std::endl;

    stack.pop();
    std::cout << "Minimum element after pop: " << stack.getMin() << std::endl;

    stack.pop();
    std::cout << "Minimum element after another pop: " << stack.getMin() << std::endl;

    return 0;
}

#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
    stack<int> st1;
    stack<int> st2;
public:
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        while(st1.size()!=1){
            st2.push(st1.top());
            st1.pop();
        }
        int ans=st1.top();
        st1.pop();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
        
    }
    
    int peek() {
        while(st1.size()!=1){
            st2.push(st1.top());
            st1.pop();
        }
        int ans=st1.top();
        //st1.pop();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }
    
    bool empty() {
        return st1.empty();
    }
};

int main(){
	MyQueue q;
	q.push(10);
	q.push(20);
	cout<<q.peek()<<endl;
	q.pop();
	if(q.empty()){
		cout<<"Empty Queue";
	}
	else{
		cout<<q.peek();
	}
	return 0;
}

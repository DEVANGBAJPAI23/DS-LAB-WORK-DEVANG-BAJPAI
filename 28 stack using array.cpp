#include <iostream>

using namespace std;

class stack{
    public:

        int *arr;
        int top;
        int size;
    stack(int size){
        this -> size = size;
        arr = new int(size);
        top = -1;
    }
    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;

        }
        else{
            cout << "stack overflow" << endl;
        }
    }
    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout << "stack underflow" << endl;
        }
    }
    int peek(){
        if( top >= 0){
            return arr[top];
        }
        else{
            cout << "not have any element";
        }
    }
    bool isempty(){
        if(top == -1){
            return 1;
        }
        else{
            return 0;
        }
    }
};
int main(){
    stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);
    

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    if(st.isempty()) {
        cout << "Stack is Empty  " << endl;
    }
    else{
        cout << "Stack is not Empty  " << endl;
    }
   
}

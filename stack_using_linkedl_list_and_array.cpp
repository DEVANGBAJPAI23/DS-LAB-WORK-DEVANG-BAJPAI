class Node{ 
    public:
    int val; 
    Node* next;
    Node(int data){
        this->val=data;
        this->next=NULL;
        }};
    class Stack{
        Node* head;
        int capacity; 
        int currSize; 
        Stack(int c){ 
            this->capacity=c; 
            this->currSize=0;
            head=NULL; 
        }
        bool isEmpty(){
            return this->head==NULL;
        }
        bool isFull(){
            return this->currSize==this->capacity;
        }
        void push(int data){
            if (this->capacity==this->currSize) 
            {
                cout<<"Overflow";
                return;
            }
            Node* new_node=new Node(data);
            new_node->next=this->head; 
            this->head=new_node; 
            this->currSize++; 
        }
        int pop(){ 
            if (this->currSize==NULL)
            {
                cout<<"Underflow";
                return;
            }
            Node* new_head=this->head->next;
            this->head->next=NULL;
            Node* tobeRemoved=this->head;
            int result=tobeRemoved->val;
            delete tobeRemoved;
            this->head=new_head;
            return result;
        } 
        int getTop(){
            if (this->head==NULL) 
            {
                cout<<"Underflow";
                return;
            }
            return this->head->val;
        }
        int size(){
            return this->currSize;
            } 
};


class Stack{ 
    int capacity;
    int* arr; 
    int top; 
    public:
    Stack(int c){ 
        this->capacity=c; 
        arr=new int[c]; 
        this->top=-1;} 
        void push(int data){
            if(this->top==this->capacity-1){
                cout<<"Overflow"<<endl; 
                return ; } 
                this->top++; 
                this->arr[this->top]=data; 
                } 
                int pop(){ 
                if(this->top==-1){ 
                    cout<<"underflow";
                    return INT_MIN; 
                } 
                this->top--; 
                } 
                int gettop(){ 
                if (this->top==-1) 
                {
                    cout<<"Underflow";
                    return INT_MIN; 
                } 
                return this->arr[this->top]; 
            } 
            bool isEmpty(){ 
                return this->top==-1; 
            } 
            int size(){ 
                return this->top + 1; 
            } 
            bool isFull(){ 
                return this->top==this->capacity-1; 
            }};
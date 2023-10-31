#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildingtree(node*root){
    int data;
    cout << "enter the data" << endl;
    cin >> data;
    root = new node(data);
    if(data == -1){
        return NULL;
    }
    cout << "enter the left value of " << data << endl;
    root -> left = buildingtree(root -> left);
    cout << "enter the right value of " << data << endl;
    root -> right = buildingtree(root -> right);
    return root;
}
void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout<<  root->data<<" ";
    preorder(root -> left);
    
    preorder(root -> right);
}
int main(){
    node* root = NULL;
     root = buildingtree(root);
    //preorder traveral
    preorder(root);

}

#include <iostream>
#include <queue>
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
void inorder(node* root){
    if(root == NULL){
        return;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);

}
int main(){
    node* root = NULL;
     root = buildingtree(root);
    
    inorder(root);

}

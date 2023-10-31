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
int height(node* root){
    if(root == NULL){
        return 0;
    }

    int left = height(root -> left);
    int right = height(root -> right);

    int res = max(left, right) + 1;

    return res;
}

int diameter(node* root){
    if(root == NULL){
        return 0;
    }

    int left = diameter(root -> left);
    int right = diameter(root -> right);
    int max1 = height(root -> left) + height(root -> right) + 1;
    return max(left, max(right, max1));

}
int main(){
    node* root = NULL;
     root = buildingtree(root);
    
    int diameteroftree = diameter(root);
    cout << "the diameter of the tree is " << diameteroftree ;

}

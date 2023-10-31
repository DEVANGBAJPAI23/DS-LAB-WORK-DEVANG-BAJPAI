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

node* lca(node* root ,int n1 ,int n2 )
    {
       //base case
        if(root == NULL)
        {
            return NULL;
        }
        
        if(root->data == n1 || root->data == n2) 
        {
            return root;
        }
        
        node* leftAns = lca(root->left, n1, n2);
        node* rightAns = lca(root->right, n1, n2);
        
        if(leftAns != NULL && rightAns != NULL) 
        {
            return root;
        }
        else if(leftAns != NULL && rightAns == NULL)
            return leftAns;
        else if(leftAns == NULL && rightAns != NULL)
            return rightAns;
        else
            return NULL;
    }


int main(){
    node* root = NULL;
     root = buildingtree(root);
    
    node * lowestcommonancester = lca(root, 4, 5);
    cout << " the lowest common ancestor is " << lowestcommonancester -> data ;

}

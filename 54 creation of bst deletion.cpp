#include <iostream>
#include <queue>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* insertintobst(node* root , int d){
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(d > root -> data){
        root->right = insertintobst(root -> right, d);
    }
    else{
        root -> left = insertintobst(root -> left, d);
    }

    return root;
}

void levelorder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " " ;
            if(temp -> left){
                q.push(temp -> left);

            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}
node* deletion(node*root, int d){
    if(root == NULL){
        return root;
    }
    if(root -> data == d){
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        if(root -> left && !root -> right){
            node* temp = root -> left;
            delete root;
            return temp;
        }
         if(!root -> left && root -> right){
            node* temp = root -> right;
            delete root;
            return temp;
        }
         if(root -> left && root -> right){
            int mini = minimum(root -> right);
            root -> data = mini;
            root -> right = deletion(root -> right, mini);
        }

    }
    else if(root -> data > d){
          root -> left = deletion(root -> left, d);
          return root;
    }
    else{
         root -> right = deletion(root -> right, d);
         return root;
    }
}
void takeinput(node* &root){
    int data ;
    cin >> data;
    while(data != -1){
        root = insertintobst(root, data);
        cin >> data;
    }
}


int main(){
    node *root = NULL;
    cout <<  " enter the data" << endl;
    takeinput(root);
    levelorder(root);
    node* temp = deletion(root, 3);
    cout<<"after deleting"<<endl;
    levelorder(temp);

}

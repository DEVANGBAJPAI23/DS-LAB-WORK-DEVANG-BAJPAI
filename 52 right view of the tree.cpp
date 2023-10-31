#include <iostream>
#include <queue>
#include <bits/stdc++.h>
#include <vector>
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
void solve1(node* root, vector<int> &ans, int level){
    if(root == NULL){
        return ;
    }
    if(level == ans.size()){
        ans.push_back(root -> data);
    }
    solve1(root -> right, ans, level + 1);
    solve1(root -> left, ans, level + 1);
    
}

vector<int> rightview(node*root){
    vector<int> ans;
    solve1(root, ans, 0);
    return ans;
}
int main(){
    node* root = NULL;
     root = buildingtree(root);
    
    vector<int> rightviewtraversal = rightview(root);
    cout << "the right view of tree is " ;
    for (auto i : rightviewtraversal)
        cout << i<<" ";


}

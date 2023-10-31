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
vector<int> topview(node*root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int, int> m;
    
    queue<pair<node*, int>> q;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();

        node*frontend = temp.first;
        int hd = temp.second;
        if(m.find(hd) == m.end()){
            m[hd] = frontend -> data;
        }
        if(frontend -> left){
            q.push(make_pair(frontend -> left, hd - 1));
        }
        if(frontend -> right){
            q.push(make_pair(frontend -> right, hd + 1));
        }
    }
    for(auto i : m){
        ans.push_back(i.second);
    }
    return ans;
}
int main(){
    node* root = NULL;
     root = buildingtree(root);
    
    vector<int> topviewtraversal = topview(root);
    cout << "the top view of tree is " ;
    for (auto i : topviewtraversal)
        cout << i<<" ";


}

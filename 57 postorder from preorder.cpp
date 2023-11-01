#include<iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
TreeNode* converter(vector<int> &preorder,int s,int e){
    if(s>e)return NULL;
    int root=preorder[s];
    TreeNode* r=new TreeNode(root);
    if (s==e)
    {
        /* code */
        return r;
    }
    
    int temp=-1;
    for (int i = s+1; i <= e; i++)
    {
        /* code */
        if (preorder[i]>root)
        {
            /* code */
            temp=i;
            break;
        }
        
    }
    r->left=converter(preorder,s+1,temp-1);
    r->right=converter(preorder,temp,e);
    return r;
}
};
void PC(TreeNode* final,vector<int> &postorder){
    if(final==NULL)return;
    if(final==NULL)return;
    PC(final->left,postorder);
    PC(final->right,postorder);
    postorder.push_back(final->val);
    return;
}
int main(){
    Solution ss;
    vector<int> preorder;
    preorder.push_back(100);
    preorder.push_back(20);
    preorder.push_back(10);
    preorder.push_back(30);
    preorder.push_back(200);
    preorder.push_back(150);
    preorder.push_back(300);
    TreeNode* final=ss.converter(preorder,0,6);
    cout<<"PreOrder is : ";
    for(auto i : preorder){
      cout << i << " ";
    }
    cout << endl;
    vector<int> postorder;
    PC(final,postorder);
    cout<<"PostOrder is : ";
    for (int i = 0; i < postorder.size(); i++)
    {
        /* code */
        cout<<postorder[i]<<"   ";
    }
    cout << endl;
    
    return 0;
}

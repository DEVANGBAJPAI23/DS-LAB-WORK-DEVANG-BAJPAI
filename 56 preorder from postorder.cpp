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
TreeNode* converter(vector <int> &postorder,int s,int e){
    if(s>e)return NULL;
    int root=postorder[e];
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
        if (postorder[i]>root)
        {
            /* code */
            temp=i;
            break;
        }
        
    }
    r->left=converter(postorder,s,temp-1);
    r->right=converter(postorder,temp,e-1);
    return r;
}
};
void PC(TreeNode* final,vector<int> &preorder){
    if(final==NULL)return;
    if(final==NULL)return;
    preorder.push_back(final->val);
    PC(final->left,preorder);
    PC(final->right,preorder);
    return;
}
int main(){
    Solution ss;
    vector<int> postorder;
    postorder.push_back(10);
    postorder.push_back(30);
    postorder.push_back(20);
    postorder.push_back(150);
    postorder.push_back(300);
    postorder.push_back(200);
    postorder.push_back(100);
    TreeNode* final=ss.converter(postorder,0,6);
    cout << "postorder : " << endl;
    for(auto i : postorder){
      cout << i << " ";
    }
    cout << endl;
    vector<int> preorder;
    PC(final,preorder);
    cout << "Preorder : "<<endl;
    for (int i = 0; i < preorder.size(); i++)
    {
        /* code */
        cout<<preorder[i]<<"   ";
    }
    
    return 0;
}

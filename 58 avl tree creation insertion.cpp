
#include <iostream>
#include <math.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    int height; 

    TreeNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};


int getHeight(TreeNode* node) {
    return (node != nullptr) ? node->height : 0;
}


void updateHeight(TreeNode* node) {
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
}


TreeNode* rotateRight(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}


TreeNode* rotateLeft(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}


TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        
        return root;
    }

    updateHeight(root);

    int balance = getHeight(root->left) - getHeight(root->right);

    
    if (balance > 1) {
        if (value < root->left->data) {
            
            return rotateRight(root);
        } else {
            
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }
    
    if (balance < -1) {
        if (value > root->right->data) {
            
            return rotateLeft(root);
        } else {
            
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}


void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = nullptr;

    
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    
    inorderTraversal(root);
    cout << endl;

   
    return 0;
}

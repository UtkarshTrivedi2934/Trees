#include <bits/stdc++.h> 

    class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

BinaryTreeNode<int>* solve(vector<int> &preorder, int mini, int maxi, int &i){
    if(i == preorder.size()) return NULL;
    if(preorder[i] < mini || preorder[i] > maxi) return NULL;

    int element = preorder[i]; i++;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int> (element);
    
    root->left = solve(preorder, mini, element, i);
    root->right = solve(preorder, element, maxi, i);

    return root; 
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder, mini, maxi, i);
}


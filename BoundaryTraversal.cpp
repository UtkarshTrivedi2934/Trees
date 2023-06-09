#include<bits/stdc++.h>
using namespace std;

class node
{
public:
  int data;
  node *left;
  node *right;

  node(int d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }
};

node *buildTree(node *root)
{
  int data = 0;
  cin >> data;
  root = new node(data);
  if (data == -1)
    return NULL;
  cout << "Enter data for inserting in left of " << data << endl;
  root->left = buildTree(root->left);
  cout << "Enter data for inserting in right of " << data << endl;
  root->right = buildTree(root->right);
}

void TraverseLeft(node *root,vector<int> &ans) {
    if(root == NULL or (!root->left and !root->right))
    return;

    ans.push_back(root->data);
    if(root->left)
    TraverseLeft(root->left,ans);
    else
    TraverseLeft(root->right,ans);
}

void TraverseRight(node *root,vector<int> &ans) {
    if(root == NULL or (!root->left and !root->right))
    return;

    if(root->right)
    TraverseRight(root->right,ans);
    else
    TraverseRight(root->left,ans);
    ans.push_back(root->data);

}

void TraverseLeaf(node *root,vector<int> &ans) {
    if(root == NULL)
    return;

    if(!root->left and !root->right)
    {
        ans.push_back(root->data);
        return;
    }
    TraverseLeaf(root->left,ans);
    TraverseLeaf(root->right,ans);
}

vector<int> Boundary(node *root) {
    vector<int> ans;
    if(root == NULL)
        return ans;

    ans.push_back(root->data);

    TraverseLeft(root->left,ans);
    TraverseLeaf(root->left,ans);
    TraverseLeaf(root->right,ans);
    TraverseRight(root->right,ans);

    return ans;
}


int main()
{
    node *root = NULL;
    root = buildTree(root);
    // cout<<sumTree(root);
    
    vector<int> ans = Boundary(root);
    for(auto i:ans)
    cout<<i<<" ";
 return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
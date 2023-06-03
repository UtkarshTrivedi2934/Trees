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

void inorder(node *root,int &count) {
  if(root == NULL)
  return;

  inorder(root->left,count);
  if(!root->left and !root->right)
  count++;
  inorder(root->right,count);

}


int noOfLeafNode(node *root) {
    int count = 0;
    inorder(root,count);
    return count;
}


int main()
{
  node *root = NULL;
  root = buildTree(root);
  cout<<noOfLeafNode(root);
  return 0;
}
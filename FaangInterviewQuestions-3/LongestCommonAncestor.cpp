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


node *LCA(node *root,int n1,int n2) {
        if(!root)
        return NULL;

        if(root->data == n1 or root->data == n2)
        return root;

        node *leftAns = LCA(root->left,n1,n2);
        node *rightAns = LCA(root->right,n1,n2);

        if(!leftAns and rightAns)
        return rightAns;
        else if(!rightAns and leftAns)
        return leftAns;
        else if(rightAns and leftAns) 
        return root;
        else
        return NULL;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    int n1,n2;
    cin>>n1>>n2;
    cout<<LCA(root,n1,n2)->data;
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
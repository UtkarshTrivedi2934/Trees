// Height is balanced or not

#include<iostream>
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

bool isIdentical(node *r1,node *r2) {
    if(r1 == NULL and r2 == NULL)
    return true;
    if(r1 == NULL and r2 != NULL)
    return false;
    if(r1 != NULL and r2 == NULL)
    return false;

    bool left = isIdentical(r1->left,r2->left);
    bool right = isIdentical(r1->right,r2->right);
    bool val = r1->data == r2->data;
    if(left and right and val)
    return true;
    return false;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    
    node *root2 = NULL;
    root2 = buildTree(root2);
    cout<<isIdentical(root,root2);

 return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
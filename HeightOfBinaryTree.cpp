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

    int height(node *root) {
        if(root == NULL)
        return 0;

        int left = height(root->left);
        int right = height(root->right);

        return max(left,right) + 1;
    }

int main()
{
    node *root = NULL;
    root = buildTree(root);
    cout<<height(root);

 return 0;
}
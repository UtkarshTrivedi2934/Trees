// Longest path between any two nodes

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

pair<int,int> diameterFast(node *root) {
    if(root == NULL) 
    {
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);

    pair<int,int> ans;
    ans.first = max(left.first,max(right.first,left.second + right.second + 1));
    ans.second = max(left.second,right.second) + 1;
    return ans;
}

int diameter(node *root) {
    return diameterFast(root).first;    
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    cout<<diameter(root);

 return 0;
}
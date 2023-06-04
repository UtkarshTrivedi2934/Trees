
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

pair<bool,int> sumTreeFast(node *root) {
    //Base case
    if(root == NULL) {
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    if(root->left == NULL and root->right == NULL) {
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    //Recursion
    pair<bool,int> leftAns = sumTreeFast(root->left);
    pair<bool,int> rightAns = sumTreeFast(root->right);

    int leftSum = leftAns.second;
    int rightSum = rightAns.second;

    bool condn = root->data == leftSum + rightSum;

    pair<bool,int> ans;
    if(condn and leftAns.first and rightAns.first) {
        ans.first =  true;
        ans.second = 2*root->data;
    }
    else {
        ans.first = false;
    }
    return ans;

}

int sumTree(node *root) {
    return sumTreeFast(root).first;
}


int main()
{
    node *root = NULL;
    root = buildTree(root);
    cout<<sumTree(root);

 return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
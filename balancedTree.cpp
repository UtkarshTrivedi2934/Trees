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

int height(node *root) {
        if(root == NULL)
        return 0;

        int left = height(root->left);
        int right = height(root->right);

        return max(left,right) + 1;
    }

pair<bool,int> isBalancedFast(node *root) {
    if(root == NULL){
        pair<bool,int> p=make_pair(true,0);
        return p; 
    }

    pair<int,int> left = isBalancedFast(root->left);
    pair<int,int> right = isBalancedFast(root->right);

    bool left_ans = left.first;
    bool right_ans = right.first;


    bool diff = abs(left.second - right.second) <= 1;
    pair<bool,int> ans;
    ans.second = max(left.second,right.second) + 1;

    if(left_ans and right_ans and diff)
        ans.first = true;
    else 
    ans.first = false; 
    return ans;
}


bool Balanced(node *root) {
    return isBalancedFast(root).first;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    cout<<Balanced(root);

 return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
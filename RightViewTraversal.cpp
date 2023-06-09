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

void solve(vector<int> &ans,node *root,int level) {
    if(!root)
    return;

    if(level == ans.size())
    ans.push_back(root->data);

    solve(ans,root->right,level+1);
    solve(ans,root->left,level+1);
    
}

vector<int> RightView(node *root) {
    vector<int> ans;
    solve(ans,root,0);
    return ans;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    vector<int> ans;
    ans = RightView(root);    
    for(auto i:ans)
    cout<<i<<" ";
 return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
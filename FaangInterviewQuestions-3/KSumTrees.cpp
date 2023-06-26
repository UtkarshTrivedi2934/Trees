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

void solve(node *root,int k,int &count,vector<int> ans) {
    if(!root)
    return;

    ans.push_back(root->data);
    solve(root->left,k,count,ans);
    solve(root->right,k,count,ans);

    int sum = 0;
    for(int i = ans.size()-1;i>=0;i--) 
    {
        sum += ans[i];
        if(sum == k)
        count++;
    }
    ans.pop_back();
}

int KsumPath(node *root,int k) {
    vector<int> ans;
    int count = 0;
    solve(root,k,count,ans);
    return count;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    int k;
    cin>>k;
    cout<<KsumPath(root,k);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
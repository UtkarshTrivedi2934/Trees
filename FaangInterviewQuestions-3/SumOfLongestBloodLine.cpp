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

void solve(node *root,int sum,int &maxsum,int len,int &maxlen) {
    if(!root) {
        if(maxlen < len)
        {
            maxlen = len;
            maxsum = sum;
        }
        else if(maxlen == len) 
        maxsum = max(sum,maxsum);
        return ;
    }

    sum+=root->data;
    solve(root->left,sum,maxsum,len+1,maxlen);
    solve(root->right,sum,maxsum,len+1,maxlen);
}



int LongestBloodline(node *root) {
    int sum = 0;
    int maxsum = INT_MIN;
    int len = 0;
    int maxlen = INT_MIN;

    solve(root,sum,maxsum,len,maxlen);
    return maxsum;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    vector<int> ans;
    cout<<LongestBloodline(root);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
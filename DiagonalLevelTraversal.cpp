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

vector<int> DiagonalTraversal(node *root) {
    vector<int> ans;
    if(!root)
    return ans;

    queue<node *> q;
    q.push(root);
    while(!q.empty()) {
        node *temp = q.front();
        q.pop();
        while(temp) {
            if(temp->left)
            q.push(temp->left);
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    vector<int> ans;
    ans = DiagonalTraversal(root);    
    for(auto i:ans)
    cout<<i<<" ";
 return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
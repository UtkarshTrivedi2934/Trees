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

vector<int> ZigZagTraversal(node *root) {
    queue<node *> q;
    q.push(root);
    vector<int> result;

    bool leftToRight = true;
    while(!q.empty()) {
        int size = q.size();
        vector<int> ans(size);
        for(int i = 0;i<size;i++) {
            node *front = q.front();
            q.pop();

            int index = leftToRight ? i:size-i-1;
            ans[index] = front->data;

            if(front->left) {
                q.push(front->left);
            }
            if(front->right) {
                q.push(front->right);
            }
        }
        leftToRight = !leftToRight;
        for(auto i:ans)
        result.push_back(i);
    }
    return result;
}



int main()
{
    node *root = NULL;
    root = buildTree(root);
    // cout<<sumTree(root);
    vector<int> ans = ZigZagTraversal(root);
    for(auto i:ans)
    cout<<i<<" ";
 return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
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

vector<int> TopView(node *root) {
    map<int,int> topNode;
    vector<int> ans;
    
    if(!root)
    return ans;

    queue<pair<node *,int>> q;
    q.push(make_pair(root,0));
    while(!q.empty()) {
        pair<node *,int> temp = q.front();
        q.pop();
        
        node *frontNode = temp.first;
        int hd = temp.second;

        if(!topNode.count(hd))
            topNode[hd] = frontNode->data;

        if(frontNode->left)
            q.push(make_pair(frontNode->left,hd-1));

        if(frontNode->right)
            q.push(make_pair(frontNode->right,hd+1));
    }

    for(auto i:topNode) {
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{
    node *root = NULL;
    root = buildTree(root);
    vector<int> ans;
    ans = TopView(root);    
    for(auto i:ans)
    cout<<i<<" ";
 return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
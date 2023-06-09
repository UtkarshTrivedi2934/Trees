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

vector<int> VerticalOrder(node *root) {
    map<int ,map<int,vector<int>>> nodes;
    queue<pair<node *,pair<int,int>>> q;

    vector<int> ans;
    if(!root)
    return ans;

    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty()) {
        pair<node *,pair<int,int>> temp = q.front();

        q.pop();

        node *frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left)
        q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
        if(frontNode->right)
        q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1))); 
    }
    for(auto i:nodes){
        for(auto j:i.second) {
            for(auto k:j.second) {
                ans.push_back(k);
            }
        }
    }
    return ans;
}


int main()
{
    node *root = NULL;
    root = buildTree(root);
    vector<int> ans;
    ans = VerticalOrder(root);    
    for(auto i:ans)
    cout<<i<<" ";
 return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
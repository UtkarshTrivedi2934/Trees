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



// Level order traversal
node *levelOrder(node *root)
{
  queue<node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    node *temp;
    temp = q.front();

    q.pop();

    if (temp == NULL)
    {
      cout << endl;
      if (!q.empty())
        q.push(NULL);
    }

    else
    {
      cout << temp->data << " ";
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
    }
  }
}




//Build from Level order traversal
void levelOrderTraversal(node *&root) {
    queue<node *> q;
    int data;

    cout<<"Enter data"<<endl;
    cin>>data;
    root = new node(data);
    q.push(root);
    while(!q.empty()) {
      node *temp = q.front();
      q.pop();
      int leftData;
      cin>>leftData;
      if(leftData != -1) {
        temp->left = new node(leftData);
        q.push(temp->left);
      }

      int rightData;
      cin>>rightData;
      if(rightData != -1) {
        temp->right = new node(rightData);
        q.push(temp->right); 
      }
    }

}


node *createMapping(node *root,unordered_map<node*,node*> &NodeToParent,int target) {
    node *res = NULL;
    queue<node *> q;
    q.push(root);
    NodeToParent[root] = NULL;
    while(!q.empty()) {
        node *front = q.front();
        q.pop();

        if(front->data == target) {
            res = front;
        }

        if(front->left)
        {
            NodeToParent[front->left] = front;
            q.push(front->left);
        }

        if(front->right)
        {
            NodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int burnTree(node *root,unordered_map<node*,node*> &NodeToParent) {
    int ans = 0;
    unordered_map<node*,bool> visited;
    queue<node *>q;
    q.push(root);
    visited[root] = true;
    while(!q.empty()) {
        bool flag = 0;
        int size = q.size();
        for(int i= 0;i<size;i++) {
            node *front = q.front();
            q.pop();
            if(front->left and !visited[front->left]) {
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }

            if(front->right and !visited[front->right]) {
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }

            if(NodeToParent[front] and !visited[NodeToParent[front]]) {
                flag = 1;
                q.push(NodeToParent[front]);
                visited[NodeToParent[front]] = 1;
            }
        } 
        if(flag == 1)
            ans++;
    }
    return ans;
}

int minTime(node *root,int target) {
    int ans = 0;
    unordered_map<node*,node*> NodeToParent;
    node *targetNode = createMapping(root,NodeToParent,target);
    ans = burnTree(targetNode,NodeToParent);
    return ans;
}

int main()
{
  node *root = NULL;
  root = buildTree(root);
  // levelOrderTraversal(root);
  // levelOrder(root);
  int target;
  cin>>target;
  cout<<minTime(root,target);
  return 0;
}
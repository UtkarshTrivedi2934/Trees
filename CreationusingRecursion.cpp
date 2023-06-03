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

void inorder(node *root) {
  if(root == NULL)
  return;

  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);

}


void preorder(node *root) {
  if(root == NULL)
  return;

  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);

}


void postorder(node *root) {
  if(root == NULL)
  return;

  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
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



// Reverse Level order traversal
node* RevLevelOrder(node *root) {
  queue<node *> q;
  stack<node *> s;
  q.push(root);

  while(!q.empty()) {
  node* temp = q.front();
    q.pop();
    s.push(temp);

    if (temp->right)
        q.push(temp->right);
    
    if(temp->left) {
      q.push(temp->left);
    }
  }
      while(!s.empty()) {
      node *temp = s.top();
      cout<<temp->data<<" ";
      s.pop();
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

int main()
{
  node *root = NULL;
  levelOrderTraversal(root);
  levelOrder(root);

  // root = buildTree(root);
  // levelOrder(root);
  // cout<<endl;
  // RevLevelOrder(root);
  // cout<<endl;
  // inorder(root);
  // cout<<endl;
  // preorder(root);
  // cout<<endl;
  // postorder(root);
  return 0;
}
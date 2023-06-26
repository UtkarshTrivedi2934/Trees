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
    node *temp = q.front();
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


node *InsertIntoBST(node *&root,int data) {
    if(!root) {
        root = new node(data);
        return root;
    }
    if(data > root->data)
    InsertIntoBST(root->right,data);
    else
    InsertIntoBST(root->left,data);
    return root;
}

void takeInput(node *&root) {
    int data;
    cin>>data;
    while(data!=-1) {
        root = InsertIntoBST(root,data);
        cin>>data;
    }
}

bool Search(node *root,int x) {
    if(!root)
    return false;

    if(root->data == x)
    return true;

    if(root->data < x)
    Search(root->right,x);

    if(root->data > x)
    Search(root->left,x);
}

int main()
{
  node *root = NULL;
  takeInput(root);
//   levelOrder(root);
    int x;
    cin>>x;
    cout<<Search(root,x);
  cout<<endl;
  return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1



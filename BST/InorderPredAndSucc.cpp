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

void findPreSuc(node* root, node*& pre, node*& suc, int data)
{
    // Base case
    if (root == NULL)  return ;
 
    // If data is present at root
    if (root->data == data)
    {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }
 
        // the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            node* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        return ;
    }
 
    // If data is smaller than root's data, go to left subtree
    if (root->data > data)
    {
        suc = root ;
        findPreSuc(root->left, pre, suc, data) ;
    }
    else // go to right subtree
    {
        pre = root ;
        findPreSuc(root->right, pre, suc, data) ;
    }
}

int main()
{
  node *root = NULL;
  takeInput(root);
  int x;
  cin>>x;
  node *pre = NULL;
  node *succ = NULL;
  findPreSuc(root,pre,succ,x);
  cout<<pre->data<<endl;
  cout<<succ->data<<endl;
  return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1



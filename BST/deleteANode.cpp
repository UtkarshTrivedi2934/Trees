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

node *minValue(node *curr){
    curr = curr->right;
    while(curr!=NULL && curr->left!=NULL)
    {
        curr = curr->left;
    }
    return curr;
}

// function  for deletion 
node *deletenode(node *root, int X) {
    // your code goes here


    if(root == NULL)//base case
    return root;
    if(X<root->data)
    {
        root->left = deletenode(root->left,X);
    }
    else if(X>root->data)
    {
        root->right = deletenode(root->right,X);
    }

    else
    {
        if(root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
        
        node *temp = minValue(root);
        
        root->data = temp->data;
        
        root->right = deletenode(root->right,temp->data);
        }
        
            
        
    }
    return root;
    
    
}


int main()
{
  node *root = NULL;
  takeInput(root);
  
    int val;
    cin>>val;
    levelOrder(root);
    deletenode(root,val);
    levelOrder(root);

  cout<<endl;
  return 0;
}



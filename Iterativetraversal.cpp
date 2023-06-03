// Inorder traversal

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

void InorderIterative(node *root) {
    stack<node *> s;
    node *temp = root;
    while(true) {
        if(temp != NULL) {
            s.push(temp);
            temp = temp->left;
        } else {
            if(s.empty())
            break;
            temp = s.top();
            s.pop();
            cout<<temp->data<<" ";
            temp = temp->right;
        }
    }
}

void postOrderTraversal(node *root) {
    if(root == NULL)
    return;

    stack<node *> st;
    while(!st.empty() || root != NULL) {
      if(root!=NULL) {
        st.push(root);
        root = root->left;
      } 
      else {
        node *temp = st.top()->right;
        if(temp == NULL) {
          temp = st.top();
          st.pop();
          cout<<temp->data<<" ";
          while(!st.empty() and temp == st.top()->right) {
          temp = st.top();
          st.pop();
          cout<<temp->data<<" ";
          }
        } else {
          root = temp;
        }
      }
    }
}


void postorder(node *root) {
  if(root == NULL)
  return;

  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}

void Iterativepreorder(node* root) {
  if(root == NULL)
  return;

  stack<node *> st;
  st.push(root);
  while(!st.empty()) {
    root = st.top();
    st.pop();
    cout<<root->data<<" ";
    if(root->right!=NULL) {
      st.push(root->right);
    }
    if(root->left!=NULL) {
      st.push(root->left);
    }
  }
}

void preorder(node *root) {
  if(root == NULL)
  return;

  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);

}

int main()
{
  node *root = NULL;
  root = buildTree(root);
  inorder(root);
  cout<<endl;
  InorderIterative(root);
  cout<<endl;
  postorder(root);
  cout<<endl;
  postOrderTraversal(root);
  cout<<endl;
  Iterativepreorder(root);
  cout<<endl;
  preorder(root);
  return 0;
}

//1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
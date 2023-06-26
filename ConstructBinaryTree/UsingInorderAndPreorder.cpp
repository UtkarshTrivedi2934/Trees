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


void postorder(node *root) {
  if(root == NULL)
  return;

  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
}

int findPos(int in[],int &ele,int s,int e) {
    for(int i = s;i<=e;i++) {
        if(in[i] == ele)
        return i;
    }
    return -1;
}

node *solve(int in[],int pre[],int &index,int start,int end,int size) {
    if(index>=size or start > end) 
    return NULL;

    int ele = pre[index++];
    node *root = new node(ele);
    int position = -1; 
    position = findPos(in,ele,start,end);

    root->left = solve(in,pre,index,start,position-1,size);
    root->right = solve(in,pre,index,position+1,end,size);
    return root;
}

    node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex = 0;
        return solve(in,pre,preOrderIndex,0,n-1,n);
    } 

int main()
{
    int in[] = {1,6,8,7};
    int pre[] = {1,6,7,8};
  node *root = buildTree(in,pre,4);
    postorder(root);
  return 0;
}
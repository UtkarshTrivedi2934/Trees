//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void convertToDLL(Node *root,Node *head) {
        if(!root)
        return;
        
        convertToDLL(root->right,head);
        root->right = head;
        if(head)
        head->left = root;
        head = root;
        convertToDLL(root->left,head);
    }
    
    Node* mergeDLL(Node *head1,Node* head2) {
            Node *head = NULL;
            Node *tail = NULL;
            while(head1 and head2) {
                if(head1->data < head2->data) {
                    if(!head) {
                        head = head1;
                        tail = head1;
                        head1 = head1->right;
                    }
                    else {
                        tail->right = head1;
                        head1->left = tail;
                        tail = head1;
                        head1 = head1->right;
                    }
                } else {
                    if(!head) {
                        head = head2;
                        tail = head2;
                        head2 = head2->right;
                    }
                    else {
                        tail->right = head2;
                        head2->left = tail;
                        tail = head2;
                        head2 = head2->right;
                    }
                }
            }
            return head;
        }
        
    int Nodecount(Node *head) {
        Node *p = head;
        int count = 0;
        while(p) {
            count++;
            p = p->right;
        }
        return count;
    }
    
    Node* DLLtoBST(Node *head,int n) {
       if(n<=0 or !head) 
       return NULL;
       
  
       Node *left = DLLtoBST(head->left,n/2);
        Node *root = head;
       root->left = left;
       head = head->right;
       
       root->right =  DLLtoBST(head->right,n-n/2-1);
       return root;
    }
    
    
    Node* merge(Node *root1, Node *root2)
    {
       //Your code here
       Node* head1 = NULL;
       convertToDLL(root1,head1);
       head1->left = NULL;
       
        Node* head2 = NULL;
       convertToDLL(root2,head2);
       head2->left = NULL;
       
       Node * head = mergeDLL(head1,head2);
       
       return DLLtoBST(head,Nodecount(head));
    }

    void inorder(Node *root) {
        if(!root)
        return;

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};

//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       Node* root = obj.merge(root1, root2);
       obj.inorder(root);
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends
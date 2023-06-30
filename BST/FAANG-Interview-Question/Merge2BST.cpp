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
    
    void Inorder(Node *root,vector<int> &inorderData) {
        if(!root)
        return;
        
        Inorder(root->left,inorderData);
        inorderData.push_back(root->data);
        Inorder(root->right,inorderData);
    }
    
    vector<int> mergeArray(vector<int> &ans,vector<int> &ans2){
        vector<int> ans3(ans.size()+ans2.size());
        int i = 0;
        int j = 0;
        int k = 0;
        
        while(i<ans.size() and j<ans2.size()) {
            if(ans[i] < ans2[j])
            ans3[k++] = ans[i++];
            else
            ans3[k++] = ans2[j++];
        }
        
        while(i<ans.size())
        ans3[k++] = ans[i++];
        while(j<ans2.size())
        ans3[k++] = ans2[j++];
        return ans3;
     }
    
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> ans,ans2;
       Inorder(root1,ans);
       Inorder(root2,ans2);
       
       vector<int> ans3 = mergeArray(ans,ans2);
       return ans3;
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
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends
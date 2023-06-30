//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

/* utility that allocates a new Node
   with the given key  */
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

			// Create the right child for the current node
			currNode->right = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:

    void inorder(Node *root,vector<int> &inorderData) {
            if(!root)
            return;

            inorder(root->left,inorderData);
            inorderData.push_back(root->key);
            inorder(root->right,inorderData);
        }

    Node *inorderToBST(Node *root,vector<int> &inorderVal,int s,int e) {
        int m = (s+e)/2;
        if(s>e)
        return NULL;

        Node *root = newNode(inorderVal[m]);
        root->left = inorderToBST(root,inorderVal,s,m-1);
        root->right = inorderToBST(root,inorderVal,m+1,e);
        return root;
    }

    Node *BalancedBST(Node *root) {
        vector<int> inorderVal;
        inorder(root,inorderVal);
        
        return inorderToBST(root,inorderVal,0,inorderVal.size()-1);
    }
};

//{ Driver Code Starts.
int main() {

    int t;
	cin >> t;
	getchar();

	while (t--)
	{

		string str;
		getline(cin, str);
	
		Node *root = buildTree(str);
		Solution ob;
		ob.BalancedBST(root);
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends
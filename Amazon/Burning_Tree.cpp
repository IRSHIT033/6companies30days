// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   
int findMaxDist(unordered_map<Node *, Node *> &mp, Node *target)
{
    queue<Node *> q;
    q.push(target);
    unordered_map<Node *, int> vis;
    vis[target] = 1;
    int maxi = 0;
    while (!q.empty())
    {
        int sz = q.size();
        int fl = 0;
        for (int i = 0; i < sz; i++)
        {
            auto node = q.front();
            q.pop();
            if (node->left && !vis[node->left])
            {
                fl = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }
            if (node->right && !vis[node->right])
            {
                fl = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }
            if (mp[node] and !vis[mp[node]])
            {
                fl = 1;
                vis[mp[node]] = 1;
                q.push(mp[node]);
            }
        }
        if (fl)
            maxi++;
    }
    return maxi;
}

Node *bfs_to_map_parents(Node *root, unordered_map<Node *, Node *> &mp, int start)
{
    queue<Node *> q;
    q.push(root);
    Node *res;
    while (!q.empty())
    {
        Node *n = q.front();
        if (n->data == start)
            res = n;
        q.pop();
        if (n->left)
        {
            mp[n->left] = n;
            q.push(n->left);
        }
        if (n->right)
        {
            mp[n->right] = n;
            q.push(n->right);
        }
    }
    return res;
}

int minTime(Node *root, int target)
{
    unordered_map<Node *, Node *> mp;
    Node *tar = bfs_to_map_parents(root, mp, target);
    int maxi = findMaxDist(mp, tar);
    return maxi;
}
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends

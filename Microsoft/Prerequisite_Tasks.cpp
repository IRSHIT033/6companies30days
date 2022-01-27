// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<unordered_set<int>> create_graph(int N,vector<pair<int,int>>&prerequisites)
    {
        vector<unordered_set<int>> graph(N);
        for(auto pre :prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;    
    }
    
    bool dfs(vector<unordered_set<int>>& graph,int node, vector<bool>& onpath,vector<bool>&visited )
    {
        if(visited[node])return false;
        onpath[node]=visited[node]=true;
        for(int neigh:graph[node] )
        if(onpath[neigh]|| dfs(graph,neigh,onpath,visited))
            return true;
        return onpath[node]=false;    
    }
    
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) 
	{
	    
	    vector<unordered_set<int>>graph=create_graph(N,prerequisites);
	    vector<bool>onpath(N,false),visited(N,false);
	    for(int i=0;i<N;i++)
	        if(!visited[i] and dfs(graph,i,onpath,visited))
	          return false;
	    return true;   
	          
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends

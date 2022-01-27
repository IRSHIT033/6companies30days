// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int as=1;
    vector<int>dx{0,-1,-1,-1,0,1,1,1};
    vector<int>dy{1,1,0,-1,-1,-1,0,1};
    
    void dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0|| j<0 || i>=grid.size() || j>=grid[0].size() ||grid[i][j]==0){
            return;
        }
        as++;
        grid[i][j]=0;
        for(int k=0;k<8;k++){
            dfs(i+dx[k],j+dy[k],grid);
        }
    }
    int findMaxArea(vector<vector<int>>& grid) {
        
        int c=0;
        for(int i=0;i<grid.size();i++){
          for(int j=0;j<grid[0].size();j++){
              as=0;
              if(grid[i][j]==1)
              {
                  dfs(i,j,grid);
                  c=max(c,as);
              }
          }   
        }
        return c;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends

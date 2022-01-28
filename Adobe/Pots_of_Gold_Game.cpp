// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

   int sol(vector<int>& nums,vector<vector<int>>&dp,int s,int e)
   {
          if(s>e)return dp[s][e]=0;
          if(s==e)return dp[s][e]=nums[s];
          if(dp[s][e]!=-1)return dp[s][e];
          
          int l=nums[s]+min(sol(nums,dp,s+2,e),sol(nums,dp,s+1,e-1));
          int r=nums[e]+min(sol(nums,dp,s+1,e-1),sol(nums,dp,s,e-2));
          
          return dp[s][e]=max(l,r);
   }

    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	    return sol(A,dp,0,n-1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends

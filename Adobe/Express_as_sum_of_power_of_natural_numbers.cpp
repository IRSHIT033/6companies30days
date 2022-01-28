// { Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
    int dp[1001][1001] ;
    
    long long int p=1e9+7;
    
    int sol(int n, int x,int i)
    {
        // code here
        
        if(n==0)return 1;
        
        if(i>n)return 0;
        
        if(dp[n][i]!=-1)return dp[n][i]%p;
        
        long long int t=pow(i,x);
        
        if(t<=n){
            dp[n][i]= sol(n-t,x,i+1)+sol(n,x,i+1);
            return dp[n][i]%p;
        }
        else{
            dp[n][i]=0;
            return dp[n][i]%p;
        }
    }
    int numOfWays(int n, int x)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return sol(n, x, 1);
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends

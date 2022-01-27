// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
  
      
      int sol(int arr[],int n)
   {
      
      int sum=accumulate(arr,arr+n,0);
      n++;
      vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
      
      for(int i=0;i<n;i++)dp[i][0]=true;
      
      for(int i=1;i<n;i++){
          for(int j=1;j<sum+1;j++){
              if(arr[i-1]>j)
                  dp[i][j]=dp[i-1][j];
              else 
                  dp[i][j]=dp[i-1][j]|| dp[i-1][j-arr[i-1]];
          }
      }
      
      int mini=INT_MAX;
      
      for(int i=0;i<=sum/2;i++)
          if(dp[n-1][i]==true)
             mini=min(mini,sum-2*i);
             
             
      return mini; 
      
   }
	int minDifference(int arr[], int n)  { 
	    int res=sol(arr,n);
	    return res;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    void solve(string str,string&max,int k ,int pos){
        if(k==0)return;
        
        char maxi=str[pos];
        for(int i=pos+1;i<str.length();i++){
             if(maxi < str[i])
                maxi = str[i];
        }
        if(maxi != str[pos])
            k--;
         
          for(int i=str.length()-1; i>=pos ;i--)
        {
            if(str[i] == maxi)
            {
                swap(str[i],str[pos]);
                if(str.compare(max)>0)
                  max=str;
                  
                  solve(str,max,k,pos+1);
                  swap(str[i],str[pos]);
            }}   
    }
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string max=str;
       solve(str,max,k,0);
       return max;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends

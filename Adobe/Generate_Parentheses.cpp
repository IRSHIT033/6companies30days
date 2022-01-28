// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    void sol(string s,int open,int close,vector<string> &vs){
        if(open==0 and close==0){
            vs.push_back(s);
            return ;
        }
        if(open){
            string op1=s;
            op1.push_back('(');
            sol(op1,open-1,close,vs);
        }
        if(close>open){
            string op2=s;
            op2.push_back(')');
            sol(op2,open,close-1,vs);
        }
        return;
    }
       
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        string s;
        vector<string>v;
        sol(s,n,n,v);
        return v;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends

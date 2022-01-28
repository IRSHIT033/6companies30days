// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
       int res=0,sign=1,i=0;
       if(str[0]=='-'){
           sign=-1;
           i++;
       }
       for(;str[i]!='\0';i++){
            if(!(str[i] >='0' && str[i] <= '9'))return -1;
           res=res*10+str[i]-'0';
       }
       
       return sign*res;
       
        
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends

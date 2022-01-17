// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A)
		{
           		    vector<int>alpha(27,0);
		    string res="";
		    vector<char>v;
		    int n=A.length();
		    for(int i=0;i<n;i++)
		    {
		        if(!alpha[A[i]-'a']) v.push_back(A[i]);
		        alpha[A[i]-'a']++;
		        int flag=0;  
		        int m=v.size();
		         for(int j=0;j<m;j++)
		         {
		           if(alpha[v[j]-'a']==1){
		                 flag=1;
		                 res.push_back(v[j]);
		                 break;
		             }
		         }
		         if(flag==0)res+='#';
		         }
		    return res;  
           }
		

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends

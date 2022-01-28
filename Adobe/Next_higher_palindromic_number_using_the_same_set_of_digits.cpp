// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string N) { 
        //complete the function here
        int n=N.size();
        string s=N.substr(0,n/2);
        if(!next_permutation(s.begin(),s.end())) return "-1";
        string str=s;
        reverse(str.begin(),str.end());
        if(n%2==1) s+=N[n/2];
        return s+str;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends

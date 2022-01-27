// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    
    void solve(int a[],int N,int idx,string s,vector<string>&res ,unordered_map<int,string>&mp){
        if(idx==N){
            res.push_back(s);
            return;
        }
        string t=mp[a[idx]];
        for(int i=0;i<t.size();i++)
        solve(a,N,idx+1,s+t[i],res,mp);
        
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> res;
        unordered_map<int,string>mp;
       
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        solve(a,N,0,"",res,mp);
        return res;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends

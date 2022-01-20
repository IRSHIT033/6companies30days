// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        unordered_set<string>mp;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(mat[i][j]!=0){
                string row="row"+to_string(i)+to_string(mat[i][j]);
                string col="col"+to_string(j)+to_string(mat[i][j]);
                string box="box"+to_string((i/3)*3+j/3)+to_string(mat[i][j]);
               if(mp.find(row)!=mp.end()) { return 0;}else{ mp.insert(row);}
               if(mp.find(col)!=mp.end()) { return 0;}else{ mp.insert(col);}
               if(mp.find(box)!=mp.end()) { return 0;}else{ mp.insert(box);}
       
            }
        }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends

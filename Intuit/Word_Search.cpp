// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

   bool sol(int i,int j,vector<vector<char>>& board,string word){
       if(word.size()==0)
        return true;
       
       if(i<0|| i>=board.size() ||j<0|| j>board[0].size()|| board[i][j]!=word[0])
         return false;
        
        char c=board[i][j];
        board[i][j]='*';
        string sub=word.substr(1);
        bool found=sol(i-1,j,board,sub)||sol(i,j+1,board,sub)||sol(i+1,j,board,sub)||sol(i,j-1,board,sub);
        board[i][j]=c;
        return found;
   }


    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(sol(i,j,board,word))
                     return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends

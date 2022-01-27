// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
          vector<int>res;
   int i=0;
   int j=0;
   int col_end=c-1;
   int col_start=0;
   int row_start=1;
   int row_end=r-1;
   bool move_down=false;
   bool move_up=false;
   bool move_right=true;
   bool move_left=false;
   
   int counter = r*c;
   while(counter--){
       res.push_back(matrix[i][j]);
       if(!move_up and  !move_down){
           if(move_right and j!=col_end)j++;
           else if(move_right and j==col_end){
               move_down=true;
               col_end--;
               move_right=false;
               i++;
               }
            else if(move_left and j!=col_start){
                j--;
            }
            else if(move_left and j==col_start){
                move_up=true;
                col_start++;
                move_left=false;
                i--;
            }
       }
         else{
                if(move_down and i!=row_end){
                    i++;
                }else if(move_down and i==row_end){
                    move_down = false;
                    row_end--;
                    move_left=true;
                    j--;
                }else if(move_up and i!=row_start){
                    i--;
                }else if(move_up and i==row_start){
                    move_up = false;
                    row_start++;
                    move_right=true;
                    j++;
                }
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends

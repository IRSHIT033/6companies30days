class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), res;
        if(n<=1) return 0;   // Base Case
		
        int m = grid[0].size();
        bool flag=true;
		
        for(int i=0; i<n; i++)
		{
            for(int j=m-1; j>m-n; j--)
                if(grid[i][j] == 1)
				{
                    flag=false;
                    break;
                }
            if(flag==true)
			{
                grid.erase(grid.begin()+i);
                res = minSwaps(grid);
                return (res+i>=i) ? i+res : -1;
            }
            flag=true;
        }
        return -1;
    }
};

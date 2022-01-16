class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
                if (grid.empty())return 0;
            
        int m = grid.size(), n = grid[0].size(), days=0, total_oranges=0, cnt=0;
        queue<pair<int, int>> rotten;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                    total_oranges++;
                if (grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }
        vector<int> dx{0, 0, 1, -1}, dy{1, -1, 0, 0};
        while (!rotten.empty())
        {
            int k = rotten.size();
            cnt += k;
            while (k--)
            {
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for (int i = 0; i < 4; i++)
                {
                    int newX = x + dx[i], newY = y + dy[i];
                    if (newX < 0 || newY < 0 || newX >= m || newY >= n || grid[newX][newY]!= 1)
                        continue;
                    grid[newX][newY] = 2;
                    rotten.push({newX, newY});
                }
            }
            if (!rotten.empty())
                days++;
        }
        return total_oranges == cnt ? days : -1;
    }
};

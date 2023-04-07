class Solution {
public:
     void dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or !grid[i][j]) return;
        grid[i][j] = 0;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();
        for(int i = 0; i < grid.size(); i++) {
            dfs(grid, i, 0);
            dfs(grid, i, column - 1);
        } 
        for(int j = 0; j < column; j++) {
            dfs(grid, 0, j);
            dfs(grid, row - 1, j);
        }
        int count = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                if(grid[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};

/*
TC: O(n * n)
SC: O(n * n)
*/
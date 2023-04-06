class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();
        vector<vector<int>>ans(row + 1, vector<int>(column + 1, 123456));
        ans[0][0] = ans[0][1] = ans[1][0] = 0;
        for(int i = 1; i <= row; i++) {
            for(int j = 1; j <= column; j++) {
                ans[i][j] = grid[i - 1][j - 1] + min(ans[i - 1][j], ans[i][j - 1]);
            }
        }
        return ans[row][column];
    }
};

/*
TC: O(n ^ 2)

SC: O(n ^ 2)
*/
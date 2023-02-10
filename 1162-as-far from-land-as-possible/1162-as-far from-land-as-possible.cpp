class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        queue<pair<int, int>>q;
        vector<pair<int, int>>direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>>visited(row, vector<bool>(col, 0));
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        int distance = -1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i ++) {
                    int xx = x + direction[i].first;
                    int yy = y + direction[i].second;
                    if(xx >= 0 and xx < row and yy >= 0 and yy < col and visited[xx][yy] == false) {
                        q.push({xx, yy});
                        visited[xx][yy] = true;
                    }
                }
            }
            distance++;
        }
        return distance == 0? -1: distance;
    }
};
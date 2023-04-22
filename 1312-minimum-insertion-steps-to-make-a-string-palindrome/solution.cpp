class Solution {
public:
    int f(vector<vector<int>> &dp, string &s1, string &s2, int i, int j) {
        if(i >= s1.size() or j >= s2.size()) {
            return 0;
        } else if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(s1[i] == s2[j]) {
            return dp[i][j] = 1 + f(dp, s1, s2, i + 1, j + 1);
        } else {
            return dp[i][j] = max(f(dp, s1, s2, i + 1, j), f(dp, s1, s2, i, j + 1));
        }
    }
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>>dp(n, vector<int>(n, -1));
        int lcs = f(dp, s, t, 0, 0);
        return n - lcs;
    }
};

/* 
TC: O(n * n)
SC: O(n * n)
*/

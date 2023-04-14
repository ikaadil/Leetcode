class Solution {
public:
    int f(vector<vector<int>> &dp, string &s, int start, int end) {
        if(end < start) {
            return 0;
        } else if(start == end) {
            return 1;
        } else if(dp[start][end] != -1) {
            return dp[start][end];
        } else if(s[start] == s[end]) {
            return dp[start][end] = 2 + f(dp, s, start + 1, end - 1);
        } else {
            return dp[start][end] = max(f(dp, s, start + 1, end), f(dp, s, start, end - 1));
        }
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return f(dp, s, 0, n - 1);
    }
};

/*
TC: O(n ^ 2)
SC: O(n ^ 2)
*/
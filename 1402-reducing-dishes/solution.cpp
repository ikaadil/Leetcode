class Solution {
public:
    int f(vector<int>& satisfaction, vector<vector<int>>&dp, int index, int count) {
        if(index >= satisfaction.size() or count > satisfaction.size()) {
            return 0;
        }
        if(dp[index][count] != -1) {
            return dp[index][count];
        }
        return dp[index][count] = max(satisfaction[index] * count + f(satisfaction, dp, index + 1, count + 1), max(0, f(satisfaction, dp, index + 1, count)));
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
        return f(satisfaction, dp, 0, 1);

    }
};

/*
TC: O(n ^ 2)
SC: O(n ^ 2)

*/
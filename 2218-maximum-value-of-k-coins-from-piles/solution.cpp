class Solution {
public:
    int f(vector<vector<int>>&dp, vector<vector<int>>& piles, int index, int k) {
        if(k <= 0 or index >= piles.size()) {
            return 0;
        } 
        if(dp[index][k] != -1) {
            return dp[index][k];
        }
        int maxValue = f(dp, piles, index + 1, k);
        int currentValue = 0;
        for(int i = 0; i < piles[index].size() and k - i - 1 >= 0; i++) {
           currentValue += piles[index][i];
           maxValue = max(maxValue, currentValue + f(dp, piles, index + 1, k - i - 1)); 
        }
        return dp[index][k] = maxValue;
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>>dp(n + 1, vector<int>(k + 1, -1));
        return f(dp, piles, 0, k);
    }
};

/* 
TC: O(n * m * k)
SC: O(n * k)
*/
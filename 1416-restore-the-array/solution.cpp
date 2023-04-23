class Solution {
public:
    int mod = 1000000007;
    int f(vector<int> &dp, string &s, int &k, int i) {
        if(i >= s.size()) {
            return 1;
        } else if(dp[i] != -1) {
            return dp[i];
        } else if(s[i] == '0') {
            return dp[i] = 0;
        }
        long long int num = 0, ans = 0;
        for(int j = i; j < s.size(); j++) {
            num = num * 10 + s[j] - '0';
            if(num > k) {
                break;
            }
            ans += f(dp, s, k, j + 1);
            ans = ans % mod;
        }
        return dp[i] = ans;

    }

    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int>dp(n, -1);
        return f(dp, s, k, 0);
    }
};


/*
TC: O(n)
SC: O(n)
*/
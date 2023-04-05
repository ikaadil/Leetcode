class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long mx = 0;
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            mx = max(mx, sum / (i + 1) + bool(sum % (i + 1)));
        }
        return mx;
    }
};

/*
TC: O(n)
SC: O(1)
*/
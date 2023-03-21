class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int count = 0;
        for(int &num: nums) {
            if(num == 0) {
                count++;
            } else {
                count = 0;
            }
            ans += count;
        } 
        return ans;
    }
};

/**
TC: O(n)
SC: O(1)

*/
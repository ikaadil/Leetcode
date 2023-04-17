class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = 0;
        for(int candy: candies) {
            mx = max(mx, candy);
        }
        vector<bool>ans;
        for(int candy: candies) {
            if(candy + extraCandies >= mx) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};

/*
TC: O(n)
SC: O(1)
*/
class Solution {
public:
    int f(int x, long long success, vector<int>& potions) {
        int low = 0,  high = potions.size() - 1, index = -1; 
        while(low <= high) {
            int mid = (low + high) / 2;
            long long spell = x;
            long long product = potions[mid] * spell;
            if(product >= success) {
                index = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if(index == -1) {
            return 0;
        }
        return potions.size() - index ;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int>ans;
        for(int spell: spells) {
            ans.push_back(f(spell,success, potions));
        }
        return ans;
    }
};

/*
TC: O(mlogm + nlogm)
SC: O(1)
*/
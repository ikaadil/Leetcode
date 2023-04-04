class Solution {
public:
    int partitionString(string s) {
        unordered_map<int, int>mp;
        int cnt = 1;
        for(char ch: s) {
            if(mp.find(ch) != mp.end()) {
                cnt++;
                mp.clear();
            }
            mp[ch] = 1;
        }
        return cnt;
    }
};

/*
TC: O(n)
SC: O(1)
*/
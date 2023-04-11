class Solution {
public:
    string removeStars(string s) {
        int starCount = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == '*') {
                starCount++;
            } else if(starCount > 0) {
                starCount--;
                s[i] = '*';
            } 
        }
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '*') continue;
            s[j] = s[i];
            j++;
        }
        return s.substr(0, j);
    }
};

/*
TC: O(n)
SC: O(1)
*/

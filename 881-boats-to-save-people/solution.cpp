class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int j = n - 1;
        int cnt = 0;
        sort(people.begin(), people.end());
        for(int i = 0; i < n; i++) {
            if(people[i] == -1) continue;
            while(j > i and people[i] + people[j] > limit) {
                j--;
            }
            if(j> i and people[i] + people[j] <= limit) {
                people[i] = -1;
                people[j] = -1;
                j--;
            } 
            cnt++;
        }
        return cnt;
    }
};

/*
TC: O(nlogn + n)
SC: O(1)
*/
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i = 0; i < tasks.size(); i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        int cur = tasks[0][0], i = 0;
        vector<int>ans;
        while(i < tasks.size()) {
            while(i < tasks.size() and tasks[i][0] <= cur) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            if(!pq.empty()) {
                cur += pq.top().first;
                ans.push_back(pq.top().second);
                pq.pop();
            } else if(i <tasks.size()) {
                cur = tasks[i][0];
            }
        }
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
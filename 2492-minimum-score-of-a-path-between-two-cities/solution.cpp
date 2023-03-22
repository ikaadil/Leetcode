class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>>graph(n + 1);
        for(int i = 0; i < roads.size(); i++) {
            graph[roads[i][0]].push_back({roads[i][1], roads[i][2]}); 
            graph[roads[i][1]].push_back({roads[i][0], roads[i][2]}); 
        }
        queue<int>q;
        vector<bool>vs(n + 1, false);
        q.push(1);
        int mn = INT_MAX;
        while(!q.empty()) {
            int root = q.front();
            vs[root] =  true;
            q.pop();
            for(pair<int, int>p: graph[root]) {
                mn = min(mn, p.second);
                if(!vs[p.first]) {
                    q.push(p.first);
                }
            }
        }
        return mn;
    }
};

/**
TC: O(roads.size())
SC: O(roads.size())
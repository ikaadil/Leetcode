class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>>redGraph(n + 1), blueGraph(n + 1);
        set<pair<int, bool>>cache;
        for(vector<int>edge: redEdges) {
            redGraph[edge[0]].push_back(edge[1]);
        }
        for(vector<int>edge: blueEdges) {
            blueGraph[edge[0]].push_back(edge[1]);
        }
        queue<pair<int, bool>>q;
        for(int i = 0; i < redGraph[0].size(); i++) {
            q.push({redGraph[0][i], true});
        }
        for(int i = 0; i < blueGraph[0].size(); i++) {
            q.push({blueGraph[0][i], false});
        }
        int dist = 0;
        vector<int>distances(n, -1);
        while(!q.empty()) {
            int sz = q.size();
            dist++;
            while(sz--) {
                int node = q.front().first;
                bool flag = q.front().second;
                cache.insert({node, flag});
                if(distances[node] == -1) {
                    distances[node] = dist;
                }
                q.pop();
                if(flag) {
                    for(int i = 0; i < blueGraph[node].size(); i++) {
                        int neighbour = blueGraph[node][i];
                        if(cache.find({neighbour, false}) == cache.end()) {
                            q.push({neighbour, false});
                        }
                    }
                } else {
                    for(int i = 0; i < redGraph[node].size(); i++) {
                        int neighbour = redGraph[node][i];
                        if(cache.find({neighbour, true}) == cache.end()) {
                            q.push({neighbour, true});
                        }
                    }
                }
            }
        }
        distances[0] = 0;
        return distances;
    }
};
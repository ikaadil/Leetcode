class Solution {
public:
    void dfs(unordered_map<int, int> &dist, vector<int>& edges, vector<bool>&vs, int parent, int &mx) {
        int node = edges[parent];
        if(node == -1) return;
        if(!vs[node]) {
            dist[node] = dist[parent] + 1;
            vs[node] = true;
            dfs(dist, edges, vs, node, mx);
        } else if(dist.find(node) != dist.end()) {
            mx = max(mx, dist[parent] - dist[node] + 1);
        }
        return;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool>vs(n + 1, false);
        int mx = -1;
        for(int i = 0; i < edges.size(); i++) {
            if(vs[i] == false and edges[i] != -1) {
                unordered_map<int, int>dist;
                dist[i] = 0;
                dfs(dist, edges, vs, i, mx);
            }
        }
        return mx;
    }
};


/*
TC: O(n)
SC: O(n)
*/
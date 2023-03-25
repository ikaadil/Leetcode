class Solution {
public:
    void dfs(int parent, vector<vector<int>> &graph, vector<bool> &vs, int &cnt) {
        vs[parent] = true;
        cnt++;
        for(int node: graph[parent]) {
            if(!vs[node]) {
                dfs(node, graph, vs, cnt);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        for(vector<int>edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int>nodeInGraphs;
        vector<bool>vs(n, false);
        for(int i = 0; i < n; i++) {
            if(!vs[i]) {
                int cnt = 0;
                dfs(i, graph, vs, cnt);
                nodeInGraphs.push_back(cnt);
            }
        }
        long long sum = 0;
        for(int x: nodeInGraphs) {
            sum += x;
        }
        long long ans = 0;
        for(int x: nodeInGraphs) {
            sum -= x;
            ans += sum * x;
        }
        return ans;
    }
};

//* 4 + 8 + 2


/*

TC: O(v + e)
SC: O(v + e)

*/
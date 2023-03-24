class Solution {
public:
    void dfs(int parent, vector<vector<int>> &graph, vector<bool> & vs) {
        vs[parent] = true;
        for(int node: graph[parent]) {
            if(!vs[node]) {
                dfs(node, graph, vs);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) {
            return -1;
        }
        vector<vector<int>>graph(n);
        for(vector<int>connection: connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }
        vector<bool> vs(n, false);
        int numberOfGraph = 0;
        for(int i = 0; i < n; i++) {
            if(!vs[i]) {
                dfs(i, graph, vs);
                numberOfGraph++;
            }
        }
        return numberOfGraph - 1;

    }
};

/*

TC: O(n + e)
SC: O(n + e)
*/
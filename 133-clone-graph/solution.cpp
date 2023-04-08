/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*>cache;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) {
            return nullptr;
        }
        if(cache[node]) {
            return cache[node];
        }
        cache[node] = new Node(node -> val);
        for(Node* neighbor: node -> neighbors) {
            cache[node] -> neighbors.push_back(cloneGraph(neighbor));
        }
        return cache[node];
       
    }
};

/*
TC: O(n)
SC: O(n)
*/
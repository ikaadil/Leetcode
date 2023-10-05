/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void travel(TreeNode* root, unordered_map<int, vector<int>>&levelArray, int len, int &mx) {
        if(!root) {
            return;
        }
        levelArray[len].push_back(root -> val);
        mx = max(mx, len);
        travel(root -> left, levelArray, len + 1, mx);
        travel(root -> right, levelArray, len + 1, mx);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        unordered_map<int, vector<int>>levelArray;
        int mx =  -1;
        travel(root, levelArray, 0, mx);
        if(mx == -1) {
            return {};
        }
        vector<vector<int>>ans;
        for(int i = 0; i <= mx; i++) {
            ans.push_back(levelArray[i]);
        }
        return ans;
    }
};
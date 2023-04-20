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
    void dfs(TreeNode* root, int level, int dis, unordered_map<int, int> &mp, int &mxLen) {
       if(root == nullptr) {
           return;
       }
       if(mp.find(level) == mp.end()) {
           mp[level] = dis;
       } else {
           mxLen = max(dis - mp[level] + 1, mxLen);
       }
       dfs(root -> left, level + 1, 2 * dis, mp, mxLen);
       dfs(root -> right, level + 1, 2 * dis + 1, mp, mxLen);

    }

    int widthOfBinaryTree(TreeNode* root) {
        unordered_map<int, int> mp;
        int mxLen = 1;
        dfs(root, 0, 1, mp, mxLen);
        return mxLen;
    }
};
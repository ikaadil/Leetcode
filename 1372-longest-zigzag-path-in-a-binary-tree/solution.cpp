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
    void dfs(TreeNode* root, bool goLeft, int step, int &mxLen) {
        if(root == nullptr) {
            return;
        }
        mxLen = max(mxLen, step);
        if(goLeft) {
            dfs(root -> left, false, step + 1, mxLen);
            dfs(root -> right, true, 1, mxLen);
        } else {
            dfs(root -> right, true, step + 1, mxLen);
            dfs(root -> left, false, 1, mxLen);
        }
    }

    int longestZigZag(TreeNode* root) {
        int mxLen = 0;
        dfs(root, true, 0, mxLen);
        dfs(root, false, 0, mxLen);
        return mxLen;
    }
};

/*
TC: O(n)
SC: O(n)
*/
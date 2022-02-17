/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// @lc code=start
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (!root->left && !root->right) return 1;
        
        auto leftn = maxDepth(root->left);
        auto rightn = maxDepth(root->right);
        
        auto ans = leftn > rightn ? leftn : rightn;
        return ans+1;
    }
};
// @lc code=end


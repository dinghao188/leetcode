/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        helper(root);
        return root;
    }
    
    int sum = 0;
    void helper(TreeNode *root) {
        if (root == nullptr) return;

        helper(root->right);
        sum += root->val;
        root->val = sum;
        helper(root->left);
    }
};
// @lc code=end


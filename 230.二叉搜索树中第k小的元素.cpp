/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int ans;
    int kthSmallest(TreeNode* root, int k) {
        helper(root, k);
        return ans;
    }
    void helper(TreeNode* root, int &k) {
        if (root == nullptr) return;
        
        helper(root->left, k);
        if (k==1) {
            ans = root->val;
            --k;
            return;
        }
        --k;
        helper(root->right, k);
    }
};
// @lc code=end


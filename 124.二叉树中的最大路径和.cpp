/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

#include <algorithm>
#include <cmath>
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
    int maxPathSum(TreeNode *root) {
        ans = std::numeric_limits<int>::min();
        helper(root);
        return ans;
    }
    int helper(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int leftMaxSum = std::max(0, helper(root->left));
        int rightMaxSum = std::max(0, helper(root->right)); 
        
        ans = std::max(ans, leftMaxSum+root->val+rightMaxSum);
        
        int ret = std::max(leftMaxSum, rightMaxSum)+root->val;
        return ret > 0 ? ret : 0;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

#include <algorithm>

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
    TreeNode *prev = nullptr;
    TreeNode *s1 = nullptr;
    TreeNode *s2 = nullptr;
    
    void recoverTree(TreeNode *root) {
        helper(root);
        if (s1 && s2) {
            std::swap(s1->val, s2->val);
        }
    }
    void helper(TreeNode* root) {
        if (root == nullptr) return;
        
        helper(root->left);
        
        if (prev && prev->val > root->val) {
            if (s1 == nullptr) {
                s1 = prev;
                s2 = root;
            } else {
                s2 = root;
                return;
            }
        }
        prev = root;
         
        helper(root->right);
    }
};
// @lc code=end
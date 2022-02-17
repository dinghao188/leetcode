/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    TreeNode *pre = nullptr;

    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        auto l = root->left;
        auto r = root->right;
        if (pre) { pre->right = root; pre->left = nullptr; }
        pre = root;
        flatten(l);
        flatten(r);
    }
};
// @lc code=end


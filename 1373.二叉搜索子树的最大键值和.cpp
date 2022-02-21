/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
 */

#include <limits>
#include <array>

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

    int maxSumBST(TreeNode* root) {
        ans = 0;
        helper(root);
        return ans;
    }
    
    std::array<int,4> helper(TreeNode *root) {
        if (root == nullptr) return {1, std::numeric_limits<int>::max(), std::numeric_limits<int>::min(), 0};
        
        auto ll = helper(root->left);
        auto rr = helper(root->right);
        
        std::array<int, 4> res;
        if (ll[0] == 1 && rr[0] == 1) {
            if (ll[2] < root->val && rr[1] > root->val) {
                auto sum = ll[3]+rr[3]+root->val;
                if (sum > ans) ans = sum;
                return {1, std::min(ll[1], root->val), std::max(rr[2], root->val), sum};
            }
        }

        return {0};
    }
};
// @lc code=end


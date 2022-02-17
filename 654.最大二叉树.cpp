/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

#include <vector>
using namespace std;

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums.begin(), nums.end());
    }
    
    TreeNode* helper(vector<int>::iterator from, vector<int>::iterator to) {
        if (from == to) return nullptr;

        vector<int>::iterator maxi = from, i = from;
        while (i < to) {
            if (*i > *maxi) maxi = i;
            ++i;
        }
        
        TreeNode *res = new TreeNode(*maxi); 
        res->left = helper(from, maxi);
        res->right = helper(maxi+1, to);
        return res;
    }
};
// @lc code=end


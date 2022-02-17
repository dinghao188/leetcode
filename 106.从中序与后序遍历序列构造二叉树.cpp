/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

#include <vector>
#include <gtest/gtest.h>
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
    using Iter = vector<int>::iterator;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
    
    TreeNode* helper(vector<int> &inorder, int infrom, int into, vector<int> &postorder, int postfrom, int postto) {
        if (infrom == into || postfrom == postto) return nullptr;

        auto post = postto-1; 
        auto in = infrom;
        while (in < into && inorder[in] != postorder[post]) ++in;
        
        TreeNode *root = new TreeNode(inorder[in]);
        root->left = helper(inorder, infrom, in, postorder, postfrom, postfrom+(in-infrom));
        root->right = helper(inorder, in+1, into, postorder, postfrom+(in-infrom), post);
        return root;
    }
};
// @lc code=end

TEST(_106, buildTree) {
    Solution s;
    
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    s.buildTree(inorder, postorder);
}

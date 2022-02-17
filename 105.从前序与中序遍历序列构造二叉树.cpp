/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

#include <vector>
#include <algorithm>
#include <iostream>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    TreeNode *buildTree(vector<int>::iterator prefrom, vector<int>::iterator preto, vector<int>::iterator infrom, vector<int>::iterator into)
    {
        if (prefrom == preto) return nullptr;
        auto tmp = find(infrom, into, *prefrom);
        TreeNode *root = new TreeNode(*prefrom);
        root->left = buildTree(prefrom+1, prefrom+1+(tmp-infrom), infrom, tmp);
        root->right = buildTree(prefrom+1+(tmp-infrom), preto, tmp+1, into);
        return root;
    }
};
// @lc code=end


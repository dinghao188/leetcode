/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

#include <vector>
#include <stack>
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
    void pushAllLeft(TreeNode *root, stack<TreeNode *> &st) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> ans;
        stack<TreeNode*> st;
        pushAllLeft(root, st);
        
        TreeNode *visited = nullptr;
        while (!st.empty()) {
            auto cur = st.top();
            if (cur->right == visited) {
                ans.push_back(cur->val);
                st.pop();
                visited = cur;
            } else {
                pushAllLeft(cur->right, st);
                visited = nullptr;
            }
        }
        return ans;
    }
};
// @lc code=end


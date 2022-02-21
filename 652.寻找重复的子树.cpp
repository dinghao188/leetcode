/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
 */

#include <vector>
#include <string>
#include <set>
#include <unordered_map>
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
    unordered_map<string, int> pp;

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        traverse(root, ans);
        return ans;
    }
    
    string traverse(TreeNode *root, vector<TreeNode*> &ans) {
        if (root == nullptr) return "#";
        
        auto l = traverse(root->left, ans);
        auto r = traverse(root->right, ans);
        string res = l + "," + r + "," + to_string(root->val);
        if (pp[res] == 1) {
            ans.push_back(root);
        }
        ++pp[res];

        return res;
    }
};
// @lc code=end


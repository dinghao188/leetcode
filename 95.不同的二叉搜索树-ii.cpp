/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return helper(1, n);
    }
    
    vector<TreeNode*> helper(int lo, int hi) {
        if (lo > hi) {
            return { nullptr };
        }
        
        vector<TreeNode*> res;
        for (int curr = lo; curr <= hi; ++curr) {
            auto lv = helper(lo, curr-1);
            auto rv = helper(curr+1, hi);
            
            for (auto ln : lv) {
                for (auto rn : rv) {
                    res. push_back(new TreeNode(curr, ln, rn));
                }
            }
        }
        return res;
    }
};
// @lc code=end


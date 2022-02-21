/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

#include <unordered_map>

// @lc code=start
class Solution {
public:
    std::unordered_map<int, int> memo;

    int numTrees(int n) {
        if (n == 0) return 1;
        
        if (memo.count(n) > 0) return memo[n];
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += numTrees(i-1) * numTrees(n-i);
        }
        memo[n] = sum;
        return sum;
    }
};
// @lc code=end


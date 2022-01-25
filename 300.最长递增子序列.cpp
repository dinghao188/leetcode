/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int ans = 0;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int k = i - 1; k >= 0; --k)
            {
                if (nums[i] > nums[k])
                    dp[i] = max(dp[i], dp[k] + 1);
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

#include <vector>
#include <algorithm>
#include <gtest/gtest.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        
        for (int i = 0; i < nums.size()-2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int targetPos = nums.size()-1;
            for (int j = i+1; j < nums.size()-1; ++j) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                
                int target = 0-nums[i]-nums[j];
                while (j < targetPos && nums[targetPos] > target) --targetPos;
                if (j == targetPos) break;
                if (nums[targetPos] == target) {
                    res.push_back({nums[i], nums[j], nums[targetPos]});
                }
            }
        }
        
        return res;
    }
};
// @lc code=end

TEST(_15, _threeSum) {
    Solution s;
    vector<int> nums = {1,2,3};
    EXPECT_EQ(s.threeSum(nums), vector<vector<int>>{});
}
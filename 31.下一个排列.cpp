/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int numsLen = nums.size();
        
        int anchor = numsLen - 2;
        while (anchor >= 0 && nums[anchor] >= nums[anchor+1]) --anchor;

        if (anchor < 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        
        int newAnchor = numsLen - 1;
        while (newAnchor > anchor && nums[newAnchor] <= nums[anchor]) --newAnchor;
        
        swap(nums[anchor], nums[newAnchor]);
        sort(nums.begin()+anchor+1, nums.end());
    }
};
// @lc code=end


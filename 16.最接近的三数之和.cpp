/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long ans = static_cast<long long>(target) + numeric_limits<int>::max();
        int n = nums.size();
        
        auto updateAns = [&](int cur) {
            if (abs(cur-target) < abs(ans-target)) ans = cur;
        };

        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i-1] == nums[i]) continue;
            
            int j = i+1, k = n-1;
            for (int j = i+1; j < n; ++j) {
                if (j > i+1 && nums[j-1] == nums[j]) continue;
                
                int k = n-1;
                while (k > j) {
                    if (k < n - 1 && nums[k] == nums[k+1]) { --k; continue; }
                    int tmp = nums[i]+nums[j]+nums[k];
                    if (tmp == target) return tmp;
                    updateAns(tmp);

                    if (tmp >= target) --k;
                    else break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end


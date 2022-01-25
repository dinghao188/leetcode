/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */

#include <algorithm>
#include <unordered_map>
#include <tuple>
using namespace std;

// @lc code=start
class Solution {
public:
    int dp(int k, int n) {
        if (k == 1) return n;
        if (n == 0) return 0;
        
        static unordered_map<int, unordered_map<int, int>> memo;
        
        if (memo.count(k) != 0 && memo[k].count(n) != 0) return memo[k][n];
        
        int res = numeric_limits<int>::max();
        int lo = 1, hi = n;
        while (lo <= hi){
            int mid = (lo+hi)>>1;
            int broken = dp(k-1, mid-1);
            int not_broken = dp(k, n-mid);
            
            if (broken > not_broken) {
                hi = mid - 1;
                res = min(res, broken+1);
            } else {
                lo = mid + 1;
                res = min(res, not_broken+1);
            }
        }
        
        memo[k][n] = res;
        return res;
    }
    int superEggDrop(int k, int n) {
        return dp(k, n);
    }
};
// @lc code=end


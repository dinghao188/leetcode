/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

#include <cmath>
#include <limits>
using namespace std;

// @lc code=start
class Solution {
public:
    int addsign(int num) {
        num = ~num + 1;
        num = num | 0x80000000;
        return num;
    }

    int divide(int dividend, int divisor) {
        long long ans = 0;
        
        long long tmpDividend = abs((long long)dividend);
        long long tmpDivisor = abs((long long)divisor);
        if (tmpDivisor == 1) {
            ans = tmpDividend;
        } else {
            while (tmpDividend - tmpDivisor >= 0)
            {
                ++ans;
                tmpDividend -= tmpDivisor;
            }
        }
        if (dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0) {
            return (ans > (long long)numeric_limits<int>::max()+1) ? numeric_limits<int>::min() : addsign(ans);
        }
        else {
            return (ans > (long long)numeric_limits<int>::max()) ? numeric_limits<int>::max() : ans;
        }
    }
};
// @lc code=end


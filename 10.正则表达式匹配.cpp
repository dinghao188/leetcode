/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool matchChar(char sc, char pc) {
        return pc == '.' || sc == pc;
    }
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.length()+1, vector<bool>(s.length()+1, false));
        dp[0][0] = true;
        
        for (int i = 0; i < p.length(); ++i) {
            if (p[i] != '*') {
                dp[i+1][0] = false;
            } else {
                dp[i+1][0] = dp[i-1][0];
            }
        }
        
        for (int i = 0; i < p.length(); ++i) {
            for (int j = 0; j < s.length(); ++j) {
                if (p[i] == '*') {
                    if (!matchChar(s[j], p[i-1])) {
                        dp[i+1][j+1] = dp[i-1][j+1];
                    } else {
                        dp[i+1][j+1] = dp[i-1][j+1] || dp[i+1][j];
                    }
                } else {
                    dp[i+1][j+1] = matchChar(s[j], p[i]) && dp[i][j];
                }
            } 
        }
        
        return dp[p.length()][s.length()];
    }
};
// @lc code=end


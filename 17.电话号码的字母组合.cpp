/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> charMap = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    
    void concat(int n, string &digits, string &res, vector<string> &ans) {
        if (n == digits.length())  {
            ans.push_back(res);
            return;
        }
        
        for (int i = 0; i < charMap[digits[n]-'0'].length(); ++i) {
            res.push_back(charMap[digits[n]-'0'][i]);
            concat(n+1, digits, res, ans);
            res.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        
        vector<string> ans;
        
        string tmp;
        concat(0, digits, tmp, ans);

        return ans;
    }
};
// @lc code=end


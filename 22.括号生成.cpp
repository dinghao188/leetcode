/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int _n;

    bool fillRightParenthsis(vector<char> &res) {
        int leftParentsis = 0;
        int rightParentsis = 0;
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] == '(') leftParentsis++;
            else {res[i] = ')'; ++rightParentsis; }
            
            if (rightParentsis > leftParentsis) return false;
        }
        return true;
    }
    void dps(vector<char> &res, int cur, int from, vector<string> &ans) {
        if (cur == _n) {
            if (res[0] != '(') return;
            if (fillRightParenthsis(res)) ans.emplace_back(res.data(), res.size());
        }
        
        for (int i = from; i < 2*_n - 1; ++i) {
            res[i] = '(';
            dps(res, cur+1, i + 1, ans);
            res[i] = 0;
        }
    }

    vector<string> generateParenthesis(int n) {
        _n = n;
        vector<char> res(2*n, '\0');
        
        vector<string> ans;
        
        dps(res, 0, 0, ans);
        return ans;
    }
};
// @lc code=end


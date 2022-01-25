/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<string> tmpRes(numRows);
        int row = 0;
        bool down = true;
        for (int i = 0; i < s.length(); ++i) {
            tmpRes[row] += s[i];

            if (down) {
                if (row + 1 < numRows) row += 1;
                else { row -= 1; down = false;}
            } else {
                if (row - 1 >= 0) row -= 1;
                else { row += 1; down = true;}
            }
        }
        
        string res;
        for (int i = 0; i < numRows; ++i) {
            res.append(tmpRes[i]);
        }
        
        return res;
    }
};
// @lc code=end


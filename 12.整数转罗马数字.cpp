/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        char res[100];
        
        int i = 0;
        while (num >= 1000) {
            res[i++] = 'M';
            num -= 1000; 
        }
        
        if (num / 100 == 9) {
            res[i++] = 'C';
            res[i++] = 'M';
            num %= 100;
        } else if (num / 100 == 4) {
            res[i++] = 'C';
            res[i++] = 'D';
            num %= 100;
        } else {
            if (num >= 500) {
                res[i++] = 'D';
                num -= 500;
            };
            while (num >= 100) {
                res[i++] = 'C';
                num -= 100;
            }
        }
        
        if (num / 10 == 9) {
            res[i++] = 'X';
            res[i++] = 'C';
            num %= 10;
        } else if (num / 10 == 4) {
            res[i++] = 'X';
            res[i++] = 'L';
            num %= 10;
        } else {
            if (num >= 50) {
                res[i++] = 'L';
                num -= 50;
            }
            while (num >= 10) {
                res[i++] = 'X';
                num -= 10;
            }
        }
        
        if (num == 9) {
            res[i++] = 'I';
            res[i++] = 'X';
        } else if (num == 4) {
            res[i++] = 'I';
            res[i++] = 'V';
        } else {
            if (num >= 5) {
                res[i++] = 'V';
                num -= 5;
            }
            while (num > 0) {
                res[i++] = 'I';
                num -= 1;
            }
        }
        
        return string(res, i);
    }
};
// @lc code=end


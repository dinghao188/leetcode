/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

#include <string>
#include <vector>
#include <string_view>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    bool matchHelper(const string &s, int start, const vector<string> &words) {
        auto tmpMM = mm;
        for (int i = 0; i < words.size(); ++i) {
            string_view tmp(s.c_str()+start+i*wordLen, wordLen);
            auto &c = tmpMM[tmp];
            if(c <= 0) return false;
            c -= 1;
        }
        return true;
    }
    unordered_map<string_view, int> mm;
    int wordLen = 0;
    int wordsLen = 0;

    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty()) return {};
        vector<int> ans;
        
        wordLen = words[0].length();
        wordsLen = words.size()*wordLen;
        
        for (int i = 0; i < words.size(); ++i) {
            mm[words[i]] += 1;
        }

        for (int i = 0; i+wordsLen <= s.length(); ++i) {
            if (mm.count(string_view(s.c_str()+i, wordLen)) == 0) continue;
            if (matchHelper(s, i, words)) ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end


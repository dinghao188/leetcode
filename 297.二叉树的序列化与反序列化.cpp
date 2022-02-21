/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

#include <string>
#include <string_view>
#include <vector>
#include <charconv>
#include <gtest/gtest.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";
        
        auto res = to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
        return res;
    }

    vector<string_view> split(const string &str, char spliter) {
        vector<string_view> res;
        
        int from = 0, to = 0;
        while (from < str.length()) {
            to = str.find(spliter, from);
            
            if (to == str.npos) {
                res.emplace_back(str.data()+from, str.length()-from);
                break;
            }

            res.emplace_back(str.data()+from, to-from);
            from = to+1;
        }
        return res;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto nodes = split(data, ',');
        int i = 0;
        return deserializeHelper(nodes, i);
    }
    TreeNode* deserializeHelper(vector<string_view> &nodes, int &from) {
        if (from == nodes.size() || nodes[from] == "#") return nullptr;
        
        int v;
        from_chars(nodes[from].data(), nodes[from].data()+nodes[from].size(), v);
        TreeNode *root = new TreeNode(v);
        ++from;
        root->left = deserializeHelper(nodes, from);
        ++from;
        root->right = deserializeHelper(nodes, from);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

TEST(_297, SplitString) {
    Codec c;
    auto res = c.split("1,2,3,4", ',');
    EXPECT_EQ(res.size(), 4);
}
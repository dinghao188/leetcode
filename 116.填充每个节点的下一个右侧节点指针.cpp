/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

#include <deque>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        connect2Node(root->left, root->right);
        return root;
    }
    
    void connect2Node(Node *ln, Node *rn) {
        if (ln == nullptr || rn == nullptr) return;
        
        ln->next = rn;
        connect2Node(ln->left, ln->right);    
        connect2Node(rn->left, rn->right);
        connect2Node(ln->right, rn->left);
    }
};
// @lc code=end


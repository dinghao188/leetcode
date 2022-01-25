/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *left = head, *right = head;
        for (int i = 0; i < n; ++i) {
            if (right == nullptr) return head; 
            
            right = right->next;
        }
        
        if (right == nullptr) return head->next;
        
        while (right->next != nullptr) {
            left = left->next;
            right = right->next;
        }
        
        left->next = left->next->next;
        
        return head;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
public:
    ListNode* reverseAll(ListNode *head, ListNode *tail) {
        ListNode *pre = nullptr;
        
        while (head != tail) {
            auto tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        
        ListNode *kTail = head;
        for (int i = 0; i < k; ++i) {
            if (kTail == nullptr) return head;
            kTail = kTail->next;
        }
        
        ListNode *newHead = reverseAll(head, kTail);
        head->next = reverseKGroup(kTail, k);
        return newHead;
    }
};
// @lc code=end


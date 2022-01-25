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
    ListNode* reverseAll(ListNode *head) {
        ListNode res;
        
        while (head) {
            auto tmp = head->next;
            head->next = res.next;
            res.next = head;
            head = tmp;
        }
        
        return res.next;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *kHead = head, *kTail = head;

        ListNode *ans = nullptr;
        ListNode *pre = nullptr;
        while (kHead) {
            for (int i = 0; i < k-1 && kTail != nullptr; ++i, kTail = kTail->next) ;

            if (kTail) {
                auto newKHead = kTail->next;

                kTail->next = nullptr;
                auto tmp = reverseAll(kHead);
                if (!ans) ans = tmp;
                if (pre) pre->next = tmp;

                pre = kHead;
                kHead = kTail = newKHead;
            } else {
                if (pre) pre->next = kHead;
                kHead= kTail = nullptr;
            }
        }
        if (ans == nullptr) ans = head;
        return ans;

    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) break;
        }
        
        if (!fast || !fast->next) return nullptr;
        
        slow = head;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

#include <vector>
using namespace std;

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
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (fast != nullptr) slow = slow->next;
        
        slow = reverse(slow);
        
        while (slow) {
            if (slow->val != head->val) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
    
    ListNode *reverse(ListNode *head) {
        ListNode *pre = nullptr;
        while (head) {
            auto tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }
};
// @lc code=end


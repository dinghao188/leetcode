/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode(0), *tmp = head;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tmp->next = list1;
                list1 = list1->next;
            } else {
                tmp->next = list2;
                list2 = list2->next;
            }
            tmp = tmp->next;
        }
        if (list1) {
            tmp->next = list1;
        } else if (list2) {
            tmp->next = list2;
        } else {
            tmp->next = nullptr;
        }
        return head->next;
    }
};
// @lc code=end
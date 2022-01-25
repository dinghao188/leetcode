/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
class Solution {
public:
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        ListNode __head, *head = &__head, *tail = &__head;
    
        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        
        if (a) tail->next = a;
        else if (b) tail->next = b;
        else tail->next = nullptr;
        
        return __head.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        int end = lists.size() - 1;
        
        while (end > 0) {
            int i = 0, j = end;
            while (i < j) {
                auto tmp = mergeTwoLists(lists[i], lists[j]);
                lists[i] = tmp;
                lists[j] = nullptr;
                ++i; --j;
            }
            
            if (i == j) end = i;
            else end = j;
        }
        return lists[0];
    }
};
// @lc code=end


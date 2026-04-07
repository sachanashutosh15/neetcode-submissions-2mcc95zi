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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        if (list1->val > list2->val) {
            return mergeTwoLists(list2, list1);
        }
        ListNode* curr = list1;
        ListNode* p1 = list1->next;
        ListNode* p2 = list2;
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                curr->next = p1;
                p1 = p1->next;
            } else {
                curr->next = p2;
                p2 = p2->next;
            }
            curr = curr->next;
        }
        if (p1) {
            curr->next = p1;
        }
        if (p2) {
            curr->next = p2;
        }
        return list1;
    }
};

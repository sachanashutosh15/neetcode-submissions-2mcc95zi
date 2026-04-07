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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* curr = head;
        while (curr) {
            nodes.push_back(curr);
            curr = curr->next;
        }
        int i = 0, j = nodes.size() - 1;
        curr = head;
        while (i < j) {
            curr->next = nodes[j--];
            curr = curr->next;
            if (i < j) {
                curr->next = nodes[++i];
                curr = curr->next;
            }
        }
        curr->next = nullptr;
    }
};

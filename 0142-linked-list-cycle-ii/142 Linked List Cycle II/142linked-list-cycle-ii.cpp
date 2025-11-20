/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *h) {
        unordered_map<ListNode*, int> um;
        ListNode* head = h;
        while (head != NULL) {
            if (um.find(head) != um.end()) return head;

            um[head]++;
            head = head->next;
        }

        return NULL;
    }
};
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> um;

        while (headA != NULL) {
            um[headA]++; headA = headA->next;
        }

        while (headB != NULL) {
            if (um.find(headB) != um.end()) return headB;

            headB = headB->next;
        }

        return NULL;
    }
};
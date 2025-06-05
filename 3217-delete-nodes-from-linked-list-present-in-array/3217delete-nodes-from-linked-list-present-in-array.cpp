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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        bitset<100001> hasN = 0;

        for (int num: nums) hasN[num] = 1;

        ListNode dummy(0, head);
        ListNode *prev = &dummy, *temp = NULL;

        for (ListNode *current = head; current; current = current->next, delete temp) {
            if (hasN[current->val]) {
                prev->next = current->next;
                temp = current;
            } else {
                prev = prev->next;
                temp = NULL;
            }
        }

        return dummy.next;
    }
};
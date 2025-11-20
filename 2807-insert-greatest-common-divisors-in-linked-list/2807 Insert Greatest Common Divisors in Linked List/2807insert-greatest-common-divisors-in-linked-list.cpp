class Solution {
public:
    int gcd(int x, int y) {
        int b = min(__builtin_ctz(x), __builtin_ctz(y));
        if (b > 0) return gcd(x >> b, y >> b) << b;
        int r = x % y;
        return (r == 0) ? y : gcd(y, r);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head->next) return head;
        int x = head->val, y;
        for(ListNode* prev = head, *ptr = head->next; ptr; ptr = ptr->next){
            int y = ptr->val;
            ListNode* newNode = new ListNode(gcd(x, y), ptr);
            prev->next = newNode;
            prev = ptr;
            x = y;
        }
        return head;
    }
};
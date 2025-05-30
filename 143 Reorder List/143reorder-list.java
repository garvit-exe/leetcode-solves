/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    ListNode reverse(ListNode head) {
        ListNode prev = null, future = null, curr = head;
        while (curr!=null) {
            future = curr.next;
            curr.next = prev;
            prev = curr;
            curr = future;
        }
        return prev;
    }
    public void reorderList(ListNode head) {
        if (head==null || head.next==null) return;

        // find middle of the list
        ListNode slow=head, fast=slow.next;
        while (fast!=null && fast.next!=null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode fh = head, sh = slow.next;
        slow.next = null;
        sh=reverse(sh);

        ListNode dummy = new ListNode(-1);
        ListNode temp = dummy;
        while (fh!=null || sh!=null) {
            if (fh!=null) {
                temp.next = fh;
                temp = temp.next;
                fh = fh.next;
            }
            if (sh!=null) {
                temp.next = sh;
                temp = temp.next;
                sh = sh.next;
            }
        }
        head = dummy.next;
    }
}
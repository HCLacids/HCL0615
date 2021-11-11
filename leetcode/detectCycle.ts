/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function detectCycle(head: ListNode | null): ListNode | null {
    let slow = head;
    let fast = head;
    do {
        if(!fast || !fast.next) return null;
        slow = slow.next;
        fast = fast.next.next; 
    } while(slow != fast)
    fast = head;
    while(slow != fast) {
        slow = slow.next;
        fast = fast.next;
    }
    return fast;
};

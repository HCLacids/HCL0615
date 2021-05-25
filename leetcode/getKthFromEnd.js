/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var getKthFromEnd = function(head, k) {
    let p = head, q = head;
    for(let i = 0; i < k; i++) p = p .next;
    while(p){
        p = p.next;
        q = q.next;
    }
    return q;
};

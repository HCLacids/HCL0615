/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
var deleteNode = function(head, val) {
    let p = head;
    let q = head.next;
    if(head.val === val) return head.next;
    while(q){
        if(q.val === val){
            p.next = q.next;
        }
        p = p.next;
        q = q.next;
    }
    return head;
};

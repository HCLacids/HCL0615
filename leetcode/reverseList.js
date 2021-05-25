/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var reverseList = function(head) {
    let node = new ListNode();
    let p = head;
    while(p){
        let q = p.next;
        p.next = node.next;
        node.next = p;
        p = q;
    }
    return node.next;
};

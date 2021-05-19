/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {number[]}
 */
var reversePrint = function(head) {
    let res = [];
    let p;
    if(head?.val || head?.next){
        p = new ListNode(head?.val);
        p.next = head?.next;
    }else {
        p = null;
    }
    while(p){
        res.unshift(p.val);
        p = p.next;
    }
    return res;
};

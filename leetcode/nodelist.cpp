/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    /* 特判 */
    if (l1 == NULL || l2 == NULL) {
        return l1 != NULL ? l1 : l2;
    }

    struct ListNode* mergeHead = NULL;
    if (l1->val < l2->val) {
        /* 获取合并之后的链表的头节点 */
        mergeHead = l1;
        /* 将合并之后的链表挂接在新链表头节点之后 */
        mergeHead->next = mergeTwoLists(l1->next, l2);
    } else {
        mergeHead = l2;
        mergeHead->next = mergeTwoLists(l1, l2->next);        
    }

    return mergeHead;
}


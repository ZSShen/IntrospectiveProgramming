/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode *src, struct ListNode *tge)
{
    if (!src && !tge)
        return NULL;

    struct ListNode *curr, *pred;
    struct ListNode *head = NULL;
    int sum, op_src, op_tge;
    int carry = 0;
    while (src || tge) {
        op_src = (src)? src->val : 0;
        op_tge = (tge)? tge->val : 0;
        sum = carry + op_src + op_tge;

        curr = (struct ListNode*)malloc(sizeof(struct ListNode*));
        curr->next = NULL;
        curr->val = sum % 10;
        carry = sum / 10;

        if (!head)
            head = curr;
        else
            pred->next = curr;
        pred = curr;

        if (src)
            src = src->next;
        if (tge)
            tge = tge->next;
    }

    /* Please notice the last carry. */
    if (carry != 0) {
        curr = (struct ListNode*)malloc(sizeof(struct ListNode*));
        curr->next = NULL;
        curr->val = carry;
        pred->next = curr;
    }

    return head;
}
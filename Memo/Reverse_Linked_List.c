/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head)
{
    if (!head)
        return head;

    struct ListNode *pred = NULL;
    struct ListNode *curr = head;
    struct ListNode *succ;
    while (curr) {
        succ = curr->next;
        curr->next = pred;
        pred = curr;
        curr = succ;
    }

    return pred;
}
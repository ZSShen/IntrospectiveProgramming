/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (!head)
        return head;

    struct ListNode *pred = head;
    struct ListNode *curr = head->next;
    struct ListNode *succ;

    while (curr) {
        succ = curr->next;
        if (pred->val == curr->val) {
            pred->next = succ;
            free(curr);
        } else
            pred = curr;
        curr = succ;
    }

    return head;
}
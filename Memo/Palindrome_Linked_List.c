/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool traverse(struct ListNode *backward, struct ListNode **p_forward)
{
    if (backward) {
        bool ret = traverse(backward->next, p_forward);
        if (!ret)
            return false;

        if (backward->val != (*p_forward)->val)
            return false;

        *p_forward = (*p_forward)->next;
        return true;
    }

    return true;
}

bool isPalindrome(struct ListNode* head)
{
    if (!head)
        return true;

    struct ListNode *forward = head;
    return traverse(head, &forward);
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swap(struct ListNode *curr, int count)
{
    if (!curr)
        return NULL;

    struct ListNode *succ_succ = swap(curr->next, count + 1);
    if ((count >> 1 << 1) == count) {
        if (curr->next) {
            struct ListNode *succ = curr->next;
            succ->next = curr;
            curr->next = succ_succ;
            return succ;
        } else
            return curr;
    }

    return succ_succ;

}

struct ListNode* swapPairs(struct ListNode* head)
{
    return swap(head, 0);
}

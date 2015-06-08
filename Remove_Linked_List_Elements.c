/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *pred, *curr, *succ;

    curr = head;
    pred = NULL;
    while (curr) {
        succ = curr->next;
        if (curr->val == val) {
            if (curr == head)
                head = succ;
            else
                pred->next = succ;
            free(curr);
            curr = pred;
        }
        pred = curr;
        curr = succ;
    }

    return head;
}
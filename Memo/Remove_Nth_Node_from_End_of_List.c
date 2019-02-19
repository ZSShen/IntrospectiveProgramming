/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *tail, *curr, *pred;

    if (!head)
        return head;

    tail = curr = head;
    while (n > 0) {
        tail = tail->next;
        n--;
    }

    while (tail) {
        tail = tail->next;
        pred = curr;
        curr = curr->next;
    }

    if (curr == head)
        head = curr->next;
    else
        pred->next = curr->next;
    free(curr);

    return head;
}
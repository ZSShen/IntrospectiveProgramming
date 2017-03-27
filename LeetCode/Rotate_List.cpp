/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if (!head)
        return NULL;
    if (k == 0)
        return head;

    int count_node = 0;
    struct ListNode *tail = NULL;
    struct ListNode *curr = head;
    while (curr) {
        tail = curr;
        curr = curr->next;
        count_node++;
    }

    /* Notice that there maybe rotation count which is larger than node count. */
    k = k % count_node;
    if (k == 0)
        return head;

    int idx = 0;
    int idx_rotate = count_node - k;
    struct ListNode *pred = NULL;
    curr = head;
    while (idx < idx_rotate) {
        pred = curr;
        curr = curr->next;
        idx++;
    }

    pred->next = NULL;
    tail->next = head;
    return curr;
}

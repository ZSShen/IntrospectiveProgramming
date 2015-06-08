/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list_src, struct ListNode* list_tge) {
    struct ListNode *list_merge, *pred, *curr;
    int value;

    if ((!list_src) && (!list_tge))
        return NULL;

    list_merge = NULL;
    while (list_src || list_tge) {
        if (!list_src) {
            value = list_tge->val;
            list_tge = list_tge->next;
        } else if (!list_tge) {
            value = list_src->val;
            list_src = list_src->next;
        } else {
            if (list_src->val <= list_tge->val) {
                value = list_src->val;
                list_src = list_src->next;
            } else {
                value = list_tge->val;
                list_tge = list_tge->next;
            }
        }

        curr = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr->val = value;
        curr->next = NULL;
        if (!list_merge)
            list_merge = curr;
        else
            pred->next = curr;
        pred = curr;
    }

    return list_merge;
}
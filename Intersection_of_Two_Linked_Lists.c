/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *head_src, struct ListNode *head_tge)
{
    if ((!head_src) || (!head_tge))
        return NULL;

    struct ListNode *curr_src = head_src;
    struct ListNode *curr_tge = head_tge;
    int len_src = 1;
    int len_tge = 1;

    while (curr_src->next) {
        curr_src = curr_src->next;
        len_src++;
    }
    while (curr_tge->next) {
        curr_tge = curr_tge->next;
        len_tge++;
    }

    if (curr_src != curr_tge)
        return NULL;

    curr_src = head_src;
    curr_tge = head_tge;
    int iter;
    if (len_src > len_tge) {
        iter = len_src - len_tge;
        while (iter > 0) {
            curr_src = curr_src->next;
            iter--;
        }
    } else {
        iter = len_tge - len_src;
        while (iter > 0) {
            curr_tge = curr_tge->next;
            iter--;
        }
    }

    while (curr_src != curr_tge) {
        curr_src = curr_src->next;
        curr_tge = curr_tge->next;
    }

    return curr_src;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode NODE;

void reorderList(struct ListNode* head)
{
    if (!head)
        return;

    int len_list = 0;
    NODE *curr = head;
    while (curr) {
        curr = curr->next;
        len_list++;
    }

    if (len_list == 1)
        return;

    NODE **arr_node = (NODE**)malloc(sizeof(NODE*) * len_list);
    if (!arr_node)
        return;

    int idx = 0;
    curr = head;
    while (idx < len_list) {
        arr_node[idx] = curr;
        curr = curr->next;
        idx++;
    }

    NODE *succ;
    NODE *trav = NULL;
    int idx_half = len_list >> 1;
    idx = 0;
    while (idx < idx_half) {
        curr = arr_node[idx];
        succ = arr_node[len_list - idx - 1];
        curr->next = succ;

        if (!trav)
            head = curr;
        else
            trav->next = curr;
        trav = succ;

        idx++;
    }

    if ((idx_half << 1) != len_list) {
        trav->next = arr_node[idx];
        trav = trav->next;
    }

    trav->next = NULL;

    free(arr_node);
}
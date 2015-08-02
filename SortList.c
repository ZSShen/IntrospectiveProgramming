/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* sortList(struct ListNode* head)
{
    if (!head)
        return NULL;

    struct ListNode *temp = head;
    int length = 0;
    while (temp) {
        length++;
        temp = temp->next;
    }
    if (length == 1)
        return head;

    temp = (struct ListNode*)malloc(sizeof(struct ListNode*));

    int range;
    for (range = 1 ; range <= length ; range <<= 1) {
        struct ListNode *curr = temp;
        struct ListNode *left = head;
        struct ListNode *rght = head;

        while (left || rght) {
            int idx = 0;
            while ((idx < range) && rght) {
                idx++;
                rght = rght->next;
            }

            int count_left = 0;
            int count_rght = 0;
            while ((count_left < range) && (count_rght < range) && left && rght) {
                if (left->val < rght->val) {
                    curr->next = left;
                    curr = left;
                    count_left++;
                    left = left->next;
                } else {
                    curr->next = rght;
                    curr = rght;
                    count_rght++;
                    rght = rght->next;
                }
            }

            while ((count_left < range) && left) {
                curr->next = left;
                curr = left;
                count_left++;
                left = left->next;
            }
            while ((count_rght < range) && rght) {
                curr->next = rght;
                curr = rght;
                count_rght++;
                rght = rght->next;
            }

            curr->next = rght;
            left = rght;
        }

        head = temp->next;
    }

    head = temp->next;
    free(temp);
    return head;
}

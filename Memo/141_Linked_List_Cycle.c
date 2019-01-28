/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{
    if (!head)
        return false;

    struct ListNode *turtle = head;
    struct ListNode *rabbit = head->next;
    bool has_cycle = false;
    while (rabbit) {
        if (turtle == rabbit) {
            has_cycle = true;
            break;
        }
        turtle = turtle->next;
        rabbit = rabbit->next;
        if (rabbit)
            rabbit = rabbit->next;
    }

    return has_cycle;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head)
{
    if (!head)
        return NULL;

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

    if (!has_cycle)
        return NULL;

    int len_cycle = 1;
    struct ListNode *shadow = turtle->next;
    while (shadow != turtle) {
        len_cycle++;
        shadow = shadow->next;
    }

    int idx;
    turtle = head;
    do {
        shadow = turtle;
        idx = 0;
        while (idx < len_cycle) {
            shadow = shadow->next;
            idx++;
        }
        if (shadow == turtle)
            break;
        turtle = turtle->next;
    } while (true);

    return turtle;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* oddEvenList(ListNode* head)
    {
        if (!head)
            return nullptr;
        if (!head->next)
            return head;
        if (!head->next->next)
            return head;

        ListNode* head_even = head->next;
        ListNode *odd = head, *even = head->next, *front;
        while (even && even->next) {
            odd->next = even->next;
            front = even->next;
            even->next = front->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = head_even;

        return head;
    }
};
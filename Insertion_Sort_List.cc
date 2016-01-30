/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head)
    {
        if (!head)
            return head;
        if (!(head->next))
            return head;

        ListNode* curr = head->next;
        int prev_val = head->val;
        while (curr) {
            if (curr->val >= prev_val)
                prev_val = curr->val;
            else {
                int curr_val = curr->val;
                ListNode* insert = head;
                while (insert != curr) {
                    if (curr_val >= insert->val)
                        insert = insert->next;
                    else
                        break;
                }

                int memo_val = curr_val;
                while (insert != curr->next) {
                    int back_val = insert->val;
                    insert->val = memo_val;
                    memo_val = back_val;
                    insert = insert->next;
                }
            }
            curr = curr->next;
        }

        return head;
    }
};
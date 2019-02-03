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
    ListNode* oddEvenList(ListNode* head) {

        if (!head || !head->next) {
            return head;
        }

        auto odd_head = head;
        auto odd = odd_head;

        auto even_head = head->next;
        auto even = even_head;

        auto curr = even->next;
        int step = 3;
        while (curr) {
            if (step % 2 != 0) {
                odd->next = curr;
                odd = curr;
            } else {
                even->next = curr;
                even = curr;
            }

            ++step;
            curr = curr->next;
        }

        odd->next = even_head;
        even->next = nullptr;
        return odd_head;
    }
};
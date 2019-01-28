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
    bool hasCycle(ListNode *head) {

        if (!head) {
            return false;
        }

        auto turtle = head;
        auto rabbit = head;

        while (rabbit->next != nullptr &&
               rabbit->next->next != nullptr) {

            turtle = turtle->next;
            rabbit = rabbit->next->next;
            if (turtle == rabbit) {
                return true;
            }
        }

        return false;
    }
};
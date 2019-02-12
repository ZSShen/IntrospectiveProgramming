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
    void reorderList(ListNode* head) {
        if (!head) {
            return;
        }
        if (!head->next) {
            return;
        }
        if (!head->next->next) {
            return;
        }

        ListNode* pred = nullptr;
        runBackTracking(head, head, pred);
    }

private:
    void runBackTracking(ListNode*& left, ListNode* right, ListNode*& pred) {

        // Traverse to the tail node.
        if (!right) {
            return;
        }

        runBackTracking(left, right->next, pred);

        // We already mark for termination, so simply return.
        if (!left) {
            return;
        }

        if (pred) {
            pred->next = left;
        }
        auto temp = left;
        left = left->next;
        temp->next = right;
        pred = right;

        // Check for termination.
        if (left == right) {
            right->next = nullptr;
            left = nullptr;
            return;
        }
        if (left->next == right) {
            pred->next = left;
            left->next = nullptr;
            left = nullptr;
        }
    }
};

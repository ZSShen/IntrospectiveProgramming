/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @return: You should return the head of the sorted linked list, using constant space complexity.
     */
    ListNode * sortList(ListNode * head) {
        // write your code here

        if (!head) {
            return nullptr;
        }

        return mergeSort(head, nullptr);
    }

private:
    ListNode* mergeSort(ListNode* bgn, ListNode* end) {

        if (bgn->next == end) {
            bgn->next = nullptr;
            return bgn;
        }

        // Find the middle node of the list.
        auto curr = bgn;
        auto pred = bgn;

        while (curr != end) {
            pred = pred->next;
            curr = curr->next;
            if (curr != end) {
                curr = curr->next;
            }
        }

        auto left = mergeSort(bgn, pred);
        auto right = mergeSort(pred, end);

        // Merge two sorted lists.
        auto dummy = new ListNode(-1);
        curr = dummy;

        while (left && right) {
            if (left->val < right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }

        while (left) {
            curr->next = left;
            curr = curr->next;
            left = left->next;
        }
        while (right) {
            curr->next = right;
            curr = curr->next;
            right = right->next;
        }

        auto head = dummy->next;
        delete dummy;
        return head;
    }
};
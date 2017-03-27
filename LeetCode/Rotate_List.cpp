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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return head;
        }

        auto pair = traverseList(head);
        k = k % pair.first;
        if (k == 0) {
            return head;
        }

        ListNode* newHead = head;
        ListNode* pred;
        for (int i = 0 ; i < pair.first - k ; ++i) {
            pred = newHead;
            newHead = newHead->next;
        }

        pair.second->next = head;
        pred->next = nullptr;

        return newHead;
    }

private:
    std::pair<int, ListNode*> traverseList(ListNode* head) {
        int len = 0;
        ListNode* tail = nullptr;
        while (head) {
            tail = head;
            head = head->next;
            ++len;
        }
        return std::make_pair(len, tail);
    }
};
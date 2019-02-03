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
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        if (!head)
            return NULL;

        ListNode* curr = head;
        for (int i = 1 ; i < m ; ++i)
            curr = curr->next;

        int count = n - m;
        vector<ListNode*> buf;
        buf.push_back(curr);
        for (int i = 0 ; i < count ; ++i) {
            curr = curr->next;
            buf.push_back(curr);
        }

        ++count;
        for (int i = 0 ; i < count >> 1 ; ++i) {
            ListNode* front = buf[i];
            ListNode* rear = buf[count - i - 1];
            int tmp = front->val;
            front->val = rear->val;
            rear->val = tmp;
        }

        return head;
    }
};
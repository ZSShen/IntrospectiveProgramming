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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.size() == 0)
            return NULL;

        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> queue(CompareList);
        for (ListNode* curr : lists)
            if (curr)
                queue.push(curr);

        ListNode *head = NULL, *prev = NULL;
        while (queue.size() > 0) {
            ListNode* node_top = queue.top();
            ListNode* node_new = new ListNode(node_top->val);
            if (!head) {
                head = node_new;
                prev = head;
            } else {
                prev->next = node_new;
                prev = node_new;
            }

            node_top = node_top->next;
            queue.pop();
            if (node_top)
                queue.push(node_top);
        }

        return head;
    }

private:
    static bool CompareList(ListNode* src, ListNode* tge)
    {
        return src->val > tge->val;
    }
};
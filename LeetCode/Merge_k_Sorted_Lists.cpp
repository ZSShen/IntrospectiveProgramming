/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    class CompareListNode {
    public:
        bool operator() (ListNode* src, ListNode* dst) {
            return src->val > dst->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }

        std::priority_queue<ListNode*, std::vector<ListNode*>, CompareListNode> queue;
        for (ListNode* curr : lists) {
            if (curr) {
                queue.push(curr);
            }
        }

        ListNode* head = nullptr;
        ListNode* prev = nullptr;
        while (queue.size() > 0) {
            ListNode* topNode = queue.top();
            ListNode* newNode = new ListNode(topNode->val);

            if (!head) {
                head = newNode;
                prev = head;
            } else {
                prev->next = newNode;
                prev = newNode;
            }

            topNode = topNode->next;
            queue.pop();
            if (topNode) {
                queue.push(topNode);
            }
        }

        return head;
    }
};

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */

// Version 1: Priority Queue
//            Space Complexity: O(n)
//            Time Complexity: O(nlogn)

class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here

        std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
        for (const auto& list : lists) {
            auto curr = list;
            while (curr) {
                queue.push(curr->val);
                curr = curr->next;
            }
        }

        auto dummy = new ListNode(-1);
        auto pred = dummy;
        while (!queue.empty()) {
            auto curr = new ListNode(queue.top());
            pred->next = curr;
            pred = curr;
            queue.pop();
        }

        auto rtn = dummy->next;
        delete dummy;
        return rtn;
    }
};


// Version 2: Buttom-up K-way merge
//            Space Complexity: O(klogk)
//            Time Complexity: O(nlogk)

class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here

        if (lists.size() == 0) {
            return nullptr;
        }

        while (lists.size() > 1) {

            std::vector<ListNode*> temp;

            int i;
            int size = lists.size();
            for (i = 0 ; i + 1 < size ; i += 2) {
                temp.push_back(mergeTwoLists(lists[i], lists[i + 1]));
            }
            if (i < size) {
                temp.push_back(lists.back());
            }

            lists = std::move(temp);
        }

        return lists[0];
    }

private:
    ListNode* mergeTwoLists(ListNode* src, ListNode* dst) {

        auto dummy = new ListNode(-1);
        auto pred = dummy;

        while (src && dst) {
            ListNode* curr;
            if (src->val < dst->val) {
                curr = new ListNode(src->val);
                src = src->next;
            } else {
                curr = new ListNode(dst->val);
                dst = dst->next;
            }
            pred->next = curr;
            pred = curr;
        }

        if (src) {
            pred->next = src;
        } else {
            pred->next = dst;
        }

        auto rtn = dummy->next;
        delete dummy;
        return rtn;
    }
};


// Version 3: Top-down merge sort
//            Space Complexity: O(1)
//            Time Complexity: O(nlogk)

class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here

        int size = lists.size();
        if (size == 0) {
            return nullptr;
        }

        return runMergeSort(0, size - 1, lists);
    }

private:
    ListNode* runMergeSort(int l, int r, const std::vector<ListNode*>& lists) {

        if (l == r) {
            return lists[l];
        }

        int m = (l + r) >> 1;
        auto left = runMergeSort(l, m, lists);
        auto right = runMergeSort(m + 1, r, lists);
        return mergeTwoLists(left, right);
    }

    ListNode* mergeTwoLists(ListNode* src, ListNode* dst) {

        auto dummy = new ListNode(-1);
        auto pred = dummy;

        while (src && dst) {
            ListNode* curr;
            if (src->val < dst->val) {
                curr = new ListNode(src->val);
                src = src->next;
            } else {
                curr = new ListNode(dst->val);
                dst = dst->next;
            }
            pred->next = curr;
            pred = curr;
        }

        if (src) {
            pred->next = src;
        } else {
            pred->next = dst;
        }

        auto rtn = dummy->next;
        delete dummy;
        return rtn;
    }
};

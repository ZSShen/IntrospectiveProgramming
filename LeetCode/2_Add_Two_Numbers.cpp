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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        std::vector<int> nums_1;
        while (l1 != nullptr) {
            nums_1.push_back(l1->val);
            l1 = l1->next;
        }
        int size_1 = nums_1.size();

        std::vector<int> nums_2;
        while (l2 != nullptr) {
            nums_2.push_back(l2->val);
            l2 = l2->next;
        }
        int size_2 = nums_2.size();

        int size_sum = std::max(size_1, size_2) + 1;

        for (int i = size_1 ; i < size_sum ; ++i) {
            nums_1.push_back(0);
        }
        std::reverse(nums_1.begin(), nums_1.end());

        for (int i = size_2 ; i < size_sum ; ++i) {
            nums_2.push_back(0);
        }
        std::reverse(nums_2.begin(), nums_2.end());

        for (int i = size_sum - 1 ; i >= 1 ; --i) {
            nums_1[i] += nums_2[i];
            if (nums_1[i] > 9) {
                nums_1[i] -= 10;
                nums_1[i - 1] += 1;
            }
        }

        int pivot = 0;
        while (nums_1[pivot] == 0) {
            ++pivot;
        }

        ListNode* pred = nullptr;
        while (pivot < size_sum) {
            ListNode* curr = new ListNode(nums_1[pivot]);
            curr->next = pred;
            pred = curr;
            ++pivot;
        }

        return (pred != nullptr)? pred : new ListNode(0);
    }
};

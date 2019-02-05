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
    bool isPalindrome(ListNode* head) {
        return checkPalindrome(head, head);
    }

    bool checkPalindrome(ListNode*& forward, ListNode* backward) {

        if (!backward) {
            return true;
        }

        if (!checkPalindrome(forward, backward->next)) {
            return false;
        }

        bool check = forward->val == backward->val;
        forward = forward->next;
        return check;
    }
};
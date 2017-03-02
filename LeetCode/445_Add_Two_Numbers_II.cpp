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
        if (!l1 && !l2) {
            return nullptr;
        }

        int lenL1 = getListLength(l1);
        int lenL2 = getListLength(l2);

        ListNode *merge, *rtn;
        if (lenL1 > lenL2) {
            auto dummy = newDummyList(lenL1 - lenL2);
            dummy.second->next = l2;
            rtn = addTwoList(l1, dummy.first);
            deleteDummyList(dummy);
        } else if (lenL1 < lenL2){
            auto dummy = newDummyList(lenL2 - lenL1);
            dummy.second->next = l1;
            rtn = addTwoList(dummy.first, l2);
            deleteDummyList(dummy);
        } else {
            rtn = addTwoList(l1, l2);
        }

        if (rtn->val < 10) {
            merge = rtn;
        } else {
            int temp = rtn->val;
            merge = new ListNode(temp / 10);
            rtn->val = temp % 10;
            merge->next = rtn;
        }

        return merge;
    }

private:
    int getListLength(ListNode* head) {
        int len = 0;
        while (head) {
            ++len;
            head = head->next;
        }
        return len;
    }

    std::pair<ListNode*, ListNode*> newDummyList(int len) {
        ListNode* head = new ListNode(0);
        --len;

        ListNode* pred = head;        
        ListNode* curr = head;
        while (len > 0) {
            curr = new ListNode(0);
            pred->next = curr;
            pred = curr;
            --len;
        }

        return std::make_pair(head, curr);
    }

    void deleteDummyList(const std::pair<ListNode*, ListNode*>& dummy) {
        ListNode* head = dummy.first;
        ListNode* tail = dummy.second;
        
        while (head != tail) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        delete head;
    }

    ListNode* addTwoList(ListNode* src, ListNode* tge) {
        if (src == nullptr) {
            return nullptr;
        }

        ListNode* succ = addTwoList(src->next, tge->next);
        ListNode* curr = new ListNode(src->val + tge->val);
        curr->next = succ;
        if (!succ) {
            return curr;
        }
        if (succ->val < 10) {
            return curr;
        }

        int temp = succ->val;
        succ->val = temp % 10;
        curr->val += temp / 10;
        return curr;
    }
};
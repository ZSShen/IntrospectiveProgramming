/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

        if (!head) {
            return nullptr;
        }

        auto orig = head;
        while (orig) {
            auto copy = new RandomListNode(orig->label);
            copy->next = orig->next;
            orig->next = copy;
            orig = copy->next;
        }

        orig = head;
        while (orig) {
            auto copy = orig->next;
            if (orig->random) {
                copy->random = orig->random->next;
            }
            orig = copy->next;
        }

        auto copy_head = head->next;
        orig = head;
        while (orig) {
            auto copy = orig->next;
            orig->next = copy->next;
            if (copy->next) {
                copy->next = copy->next->next;
            }
            orig = orig->next;
        }

        return copy_head;
    }
};
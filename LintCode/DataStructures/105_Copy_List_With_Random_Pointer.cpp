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
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here

        if (!head) {
            return nullptr;
        }

        auto curr = head;
        while (curr) {
            auto succ = curr->next;

            auto dup = new RandomListNode(curr->label);
            dup->next = succ;
            curr->next = dup;

            curr = succ;
        }

        curr = head;
        while (curr) {

            auto random = curr->random;
            if (random) {
                curr->next->random = random->next;
            }

            curr = curr->next->next;
        }

        auto new_head = head->next;
        curr = head;
        while (curr) {

            auto dup = curr->next;

            curr->next = dup->next;
            if (curr->next) {
                dup->next = curr->next->next;
            }

            curr = curr->next;
        }

        return new_head;
    }
};
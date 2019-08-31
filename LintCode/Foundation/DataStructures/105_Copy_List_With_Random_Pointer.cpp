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

        /**
         *
         *      A -> B -> C -> ...
         *
         *  Step 1. Generate a replicated node for each node and put that copy
         *  behind the original node.
         *
         *      A -> A+ -> B -> B+ -> C -> C+ -> ...
         *
         *  Step 2. For an orignal node, follow its random pointer.
         *  Then, the node next to the pointed node would be the one that the
         *  random pointer of the replicated node should point to.
         *
         *        random
         *      A ------> C -> C+
         *   => A+ -> C+
         *
         *      -----------------------
         *      |                     |
         *      |                     v
         *      A -> A+ -> B -> B+ -> C -> C+ -> ...
         *           |                      ^
         *           |                      |
         *           ------------------------
         *
         *  Step 3. Finally, we need to split the replicated list and the
         *  original list.
         */

        if (!head) {
            return nullptr;
        }

        // Step 1.
        auto curr = head;
        while (curr) {
            auto succ = curr->next;
            auto copy = new RandomListNode(curr->label);
            copy->next = succ;
            curr->next = copy;
            curr = succ;
        }

        // Step 2.
        curr = head;
        while (curr) {
            // Note that the random pointers can be null.
            if (curr->random) {
                auto rand = curr->random->next;
                curr->next->random = rand;
            }
            curr = curr->next->next;
        }

        // Step 3.
        auto new_head = head->next;

        /**
         *  curr copy  succ
         *   |    |     |
         *   v    v     v
         *   A -> A+ -> B -> B+
         *
         *   A -> B, A+ -> B+
         */

        curr = head;
        auto copy = head->next;
        while (curr) {
            auto succ = copy->next;
            curr->next = succ;
            if (succ) {
                copy->next = succ->next;
                copy = succ->next;
            }
            curr = succ;
        }

        return new_head;
    }
};

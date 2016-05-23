/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution
{
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if (!head)
            return nullptr;

        unordered_map<RandomListNode*, int> addr_map;
        vector<RandomListNode*> addr_idx_mir;

        RandomListNode* new_head = new RandomListNode(head->label);

        addr_map.insert(make_pair(head, 0));
        addr_idx_mir.push_back(new_head);

        // Construct the mirrored linked list and record the address mappings.
        RandomListNode* ref = head->next;
        RandomListNode* pred = new_head;
        RandomListNode* curr = nullptr;
        int idx = 1;
        while (ref) {
            curr = new RandomListNode(ref->label);

            addr_map.insert(make_pair(ref, idx));
            addr_idx_mir.push_back(curr);
            ++idx;

            pred->next = curr;
            pred = curr;
            ref = ref->next;
        }

        // Fix the random pointers of the mirrored list by referencing the
        // recorded address mappings.
        ref = head;
        curr = new_head;
        while (ref) {
            if (ref->random) {
                auto iter = addr_map.find(ref->random);
                int idx = iter->second;

                RandomListNode* addr = addr_idx_mir[idx];
                curr->random = addr;
            }
            ref = ref->next;
            curr = curr->next;
        }

        return new_head;
    }
};

#define DEGREE          (26)
#define INDEX(ch)       (ch - 'a')


struct TrieNode {
    struct TrieNode* branch[DEGREE];
    bool store_word;
};
typedef struct TrieNode     NODE;


#define INIT_NODE(node)                     \
        do {                                \
            int idx = 0;                    \
            while (idx < DEGREE) {          \
                node->branch[idx] = NULL;   \
                idx++;                      \
            }                               \
            node->store_word = false;       \
        } while(0);


/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    INIT_NODE(new_node);
    return new_node;
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word) {
    int len_word = strlen(word);
    int idx_word = 0;
    NODE *pred = root;
    NODE *curr;

    while (idx_word < len_word) {
        int idx_branch = INDEX(word[idx_word]);
        curr = pred->branch[idx_branch];

        if (!curr) {
            curr = (NODE*)malloc(sizeof(NODE));
            INIT_NODE(curr);
            pred->branch[idx_branch] = curr;
        }
        pred = curr;

        idx_word++;
    }
    pred->store_word = true;
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode* root, char* word) {
    int len_word = strlen(word);
    int idx_word = 0;
    NODE *curr = root;

    while (idx_word < len_word) {
        int idx_branch = INDEX(word[idx_word]);
        curr = curr->branch[idx_branch];
        if (!curr)
            break;
        idx_word++;
    }

    if (idx_word == len_word)
        return (curr->store_word == true)? true : false;
    return false;
}

/** Returns if there is any word in the trie
    that starts with the given prefix. */
bool startsWith(struct TrieNode* root, char* prefix) {
    int len_prefix = strlen(prefix);
    int idx_prefix = 0;
    NODE *curr = root;

    while (idx_prefix < len_prefix) {
        int idx_branch = INDEX(prefix[idx_prefix]);
        curr = curr->branch[idx_branch];
        if (!curr)
            break;
        idx_prefix++;
    }

    return (idx_prefix == len_prefix)? true : false;
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
    if (!root)
        return;

    int idx = 0;
    while (idx < DEGREE) {
        if (root->branch[idx])
            trieFree(root->branch[idx]);
        idx++;
    }
    free(root);
}

// Your Trie object will be instantiated and called as such:
// struct TrieNode* node = trieCreate();
// insert(node, "somestring");
// search(node, "key");
// trieFree(node);
typedef struct NODE_ {
    int elem;
    int freq;
    struct NODE_ *left;
    struct NODE_ *right;
} NODE;

#define DIRECT_LEFT       (0)
#define DIRECT_RIGHT      (1)


void find_majority(NODE **p_root, int elem, int *major_elem, int *major_freq)
{
    NODE *pred, *curr;

    if (!(*p_root)) {
        curr = (NODE*)malloc(sizeof(NODE));
        curr->elem = elem;
        curr->freq = 1;
        curr->left = NULL;
        curr->right = NULL;
        *p_root = curr;
    } else {
        char direct;
        curr = *p_root;
        while (curr) {
            if (curr->elem == elem) {
                curr->freq++;
                break;
            } else {
                pred = curr;
                if (elem < curr->elem) {
                    curr = curr->left;
                    direct = DIRECT_LEFT;
                }
                else {
                    curr = curr->right;
                    direct = DIRECT_RIGHT;
                }
            }
        }

        if (!curr) {
            curr = (NODE*)malloc(sizeof(NODE));
            curr->elem = elem;
            curr->freq = 1;
            curr->left = NULL;
            curr->right = NULL;
            if (direct == DIRECT_LEFT)
                pred->left = curr;
            else
                pred->right = curr;
        }
    }

    if (curr->freq > *major_freq) {
        *major_elem = elem;
        *major_freq = curr->freq;
    }
}


void free_resource(NODE *root)
{
    if (!root)
        return;
    free_resource(root->left);
    free_resource(root->right);
    free(root);
}


int majorityElement(int* nums, int numsSize)
{
    int major_elem = nums[0], major_freq = 1;
    int idx = 0;
    NODE *tree = NULL;
    while (idx < numsSize) {
        find_majority(&tree, nums[idx], &major_elem, &major_freq);
        idx++;
    }
    free_resource(tree);

    return major_elem;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define NIL             (-1)
#define BUF_SIZE        (2048)

typedef struct QNODE_ {
    struct TreeNode *value;
    struct QNODE_ *next;
} QNODE;

typedef struct QUEUE_ {
    QNODE *front, *rear;
    int size;
} QUEUE;

inline void queue_init(QUEUE *p_queue)
{
    p_queue->front = NULL;
    p_queue->rear = NULL;
    p_queue->size = 0;
}

void queue_deinit(QUEUE *p_queue)
{
    QNODE *curr = p_queue->front;
    QNODE *pred;
    while (curr) {
        pred = curr;
        curr = curr->next;
        free(pred);
    }
}

void queue_push(QUEUE *p_queue, struct TreeNode *value)
{
    QNODE *curr = (QNODE*)malloc(sizeof(QNODE));
    curr->value = value;
    curr->next = NULL;

    if (!(p_queue->front)) {
        p_queue->front = curr;
        p_queue->rear = curr;
    } else {
        p_queue->rear->next = curr;
        p_queue->rear = curr;
    }

    p_queue->size++;
}

inline struct TreeNode* queue_top(QUEUE *p_queue)
{
    return p_queue->front->value;
}

inline bool queue_empty(QUEUE *p_queue)
{
    return (p_queue->size == 0)? true : false;
}

void queue_pop(QUEUE *p_queue)
{
    QNODE *curr = p_queue->front;
    p_queue->front = p_queue->front->next;
    free(curr);

    p_queue->size--;
}


void invert_tree(struct TreeNode *root)
{
    if (!root)
        return;

    invert_tree(root->left);
    invert_tree(root->right);
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int traverse_level_order(struct TreeNode *root, int *arr_odr)
{
    QUEUE queue;
    queue_init(&queue);

    int idx = 1;
    arr_odr[0] = root->val;

    queue_push(&queue, root);
    while (!queue_empty(&queue)) {
        struct TreeNode *curr = queue_top(&queue);
        queue_pop(&queue);

        if (curr->left) {
            arr_odr[idx++] = curr->left->val;
            queue_push(&queue, curr->left);
        } else
            arr_odr[idx++] = NIL;

        if (curr->right) {
            arr_odr[idx++] = curr->right->val;
            queue_push(&queue, curr->right);
        } else
            arr_odr[idx++] = NIL;
    }

    queue_deinit(&queue);
    return idx;
}

bool isSymmetric(struct TreeNode* root)
{
    if (!root)
        return true;

    int *odr_origin = (int*)malloc(sizeof(int) * BUF_SIZE);
    int *odr_invert = (int*)malloc(sizeof(int) * BUF_SIZE);

    int len_origin = traverse_level_order(root, odr_origin);
    invert_tree(root);
    int len_invert = traverse_level_order(root, odr_invert);

    int idx = 0;
    bool is_sym = true;
    while (idx < len_origin) {
        if (odr_origin[idx] != odr_invert[idx]) {
            is_sym = false;
            break;
        }
        idx++;
    }

    free(odr_origin);
    free(odr_invert);

    invert_tree(root);

    return is_sym;
}

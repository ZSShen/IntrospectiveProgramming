typedef struct RECORD_ {
    int size;
    int idx_elem;
    int *p_set;
} RECORD;


int sort_element(const void *p_src, const void *p_tge)
{
    int src = *((int*)p_src);
    int tge = *((int*)p_tge);

    if (src == tge)
        return 0;
    return (src > tge)? 1 : (-1);
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int *arr_elem, int num_elem, int **p_arr_set_size, int *p_num_set)
{
    *p_num_set = pow(2, num_elem);
    int num_set = *p_num_set;

    *p_arr_set_size = (int*)malloc(sizeof(int) * num_set);
    int *arr_set_size = *p_arr_set_size;

    int **arr_set = (int**)malloc(sizeof(int*) * num_set);

    /* Prepare the empty set. */
    int *p_set = NULL;
    arr_set_size[0] = 0;
    arr_set[0] = p_set;

    if (num_elem == 0)
        return arr_set;

    /* Sort the input elements. */
    qsort(arr_elem, num_elem, sizeof(int), sort_element);

    int idx_front = 0;
    int idx_rear = 0;
    RECORD *queue = (RECORD*)malloc(sizeof(RECORD) * num_set);
    RECORD *p_rec;

    /* Enumeate the sets containing 1 element. */
    int idx_set = 1;
    while (idx_set <= num_elem) {
        p_set = (int*)malloc(sizeof(int));
        p_set[0] = arr_elem[idx_set - 1];
        arr_set_size[idx_set] = 1;
        arr_set[idx_set] = p_set;

        p_rec = &(queue[idx_rear]);
        idx_rear++;
        p_rec->size = 1;
        p_rec->idx_elem = idx_set - 1;
        p_rec->p_set = p_set;

        idx_set++;
    }

    /* Enumerate the sets containing more than 1 elements. */
    int size_old, size_new, idx_elem_new;
    int *p_set_old, *p_set_new;
    while (idx_front < idx_rear) {
        p_rec = &(queue[idx_front]);
        idx_front++;

        if (p_rec->idx_elem == (num_elem - 1))
            continue;

        size_old = p_rec->size;
        size_new = size_old + 1;
        idx_elem_new = p_rec->idx_elem + 1;
        p_set_old = p_rec->p_set;

        /* Craft the new sets. */
        while (idx_elem_new < num_elem) {
            p_set_new = (int*)malloc(sizeof(int) * size_new);
            memcpy(p_set_new, p_set_old, sizeof(int) * size_old);
            p_set_new[size_old] = arr_elem[idx_elem_new];

            arr_set_size[idx_set] = size_new;
            arr_set[idx_set] = p_set_new;

            p_rec = &(queue[idx_rear]);
            idx_rear++;
            p_rec->size = size_new;
            p_rec->idx_elem = idx_elem_new;
            p_rec->p_set = p_set_new;

            idx_elem_new++;
            idx_set++;
        }
    }

    free(queue);

    return arr_set;
}

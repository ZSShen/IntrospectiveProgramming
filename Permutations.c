/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backtrack(int *nums, bool *visit, int size, int *p_count,
               int *p_idx, int *perm, int **arr_perm)
{

    if (*p_count == size) {
        arr_perm[*p_idx] = (int*)malloc(sizeof(int) * size);
        int idx = 0;
        while (idx < size) {
            arr_perm[*p_idx][idx] = perm[idx];
            idx++;
        }
        (*p_idx)++;
    } else {
        int idx = 0;
        while (idx < size) {
            if (visit[idx] == false) {
                visit[idx] = true;
                perm[*p_count] = nums[idx];
                (*p_count)++;
                backtrack(nums, visit, size, p_count, p_idx, perm, arr_perm);
                (*p_count)--;
                visit[idx] = false;
            }
            idx++;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize)
{
    if (numsSize == 0)
        return NULL;

    /* Count the factorial of the given size. */
    int fact = 1;
    int idx = 2;
    while (idx <= numsSize) {
        fact *= idx;
        idx++;
    }

    /* Prepare the array to store permutations. */
    int **arr_perm = (int**)malloc(sizeof(int*) * fact);

    /* Prepare the visiting flags. */
    bool *visit = (bool*)malloc(sizeof(bool) * numsSize);

    /* Prepare the storage for temporary permutation. */
    int *perm = (int*)malloc(sizeof(int*) * numsSize);

    idx = 0;
    while (idx < numsSize) {
        arr_perm[idx] = NULL;
        visit[idx] = false;
        idx++;
    }

    int count = 0;
    idx = 0;
    backtrack(nums, visit, numsSize, &count, &idx, perm, arr_perm);

    free(visit);
    free(perm);
    *returnSize = fact;
    return arr_perm;
}

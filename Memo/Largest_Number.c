
#define BUF_SIZE (100)
#define COUNT_DIGIT(x) (floor(log10(x)) + 1)


int sort_number(const void *p_src, const void *p_tge)
{
    int num_src = *((int*)p_src);
    int num_tge = *((int*)p_tge);

    char src_tge[BUF_SIZE];
    char tge_src[BUF_SIZE];
    sprintf(src_tge, "%d%d", num_src, num_tge);
    sprintf(tge_src, "%d%d", num_tge, num_src);

    int rc = strcmp(src_tge, tge_src);
    if (rc == 0)
        return 0;

    return (rc > 0)? (-1) : 1;
}


char* largestNumber(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), sort_number);

    int total_digit = 0;
    int i;
    for (i = 0 ; i < numsSize ; i++)
        total_digit += (nums[i] == 0)? 1 : COUNT_DIGIT(nums[i]);

    char *sz = (char*)malloc(sizeof(char) * (total_digit + 1));
    int len_sz = 0;
    for (i = 0 ; i < numsSize ; i++) {
        sprintf(sz + len_sz, "%d", nums[i]);
        len_sz = strlen(sz);
    }

    if (sz[0] == '0')
        sz[1] = 0;

    return sz;
}

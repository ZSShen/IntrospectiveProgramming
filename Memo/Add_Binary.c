
char* addBinary(char* a, char* b)
{
    if (!a && !b)
        return NULL;

    int len_a = a? strlen(a) : 0;
    int len_b = b? strlen(b) : 0;
    int len_sum = len_a + len_b;

    char *sum = (char*)malloc(sizeof(char) * (len_sum + 1));
    memset(sum, 0, sizeof(char) * (len_sum + 1));

    if (!a)
        strncpy(sum, b, sizeof(char) * len_b);
    else if (!b)
        strncpy(sum, a, sizeof(char) * len_a);
    else {
        int idx_sum = len_sum;
        int idx_a = len_a - 1;
        int idx_b = len_b - 1;
        char ch_a, ch_b;

        while (idx_a >= 0 || idx_b >= 0) {
            ch_a = (idx_a >= 0)? a[idx_a] - '0' : 0;
            ch_b = (idx_b >= 0)? b[idx_b] - '0' : 0;

            if (ch_a ^ ch_b == 1)
                sum[idx_sum] += 1;
            else {
                if (ch_a == 1 && ch_b == 1)
                    sum[idx_sum - 1] += 1;
            }

            /* Handle carry over. */
            if (sum[idx_sum] >= 2) {
                sum[idx_sum] -= 2;
                sum[idx_sum - 1] += 1;
            }

            idx_a--;
            idx_b--;
            idx_sum--;
        }

        /* Build the final summation string. */
        int idx_str = 0;
        if (sum[idx_sum] == 0)
            idx_sum++;
        while (idx_sum <= len_sum) {
            sum[idx_str++] = sum[idx_sum] + '0';
            sum[idx_sum++] = 0;
        }
    }

    return sum;
}

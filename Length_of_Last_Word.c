int lengthOfLastWord(char* str) {
    if (!str)
        return 0;

    int idx_end = strlen(str) - 1;
    while (idx_end >= 0) {
        if (str[idx_end] != ' ')
            break;
        idx_end--;
    }
    int idx_bgn = idx_end;
    while (idx_bgn >= 0) {
        if (str[idx_bgn] == ' ')
            break;
        idx_bgn--;
    }

    return idx_end - idx_bgn;
}
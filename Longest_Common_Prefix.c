#define RETURN_DUMMY()                                  \
        do {                                            \
            char *dummy = malloc(sizeof(char) * 1);     \
            dummy[0] = 0;                               \
            return dummy;                               \
        } while(0);


char* longestCommonPrefix(char** arr_str, int num_str) {
    if ((!arr_str) || (num_str == 0))
        RETURN_DUMMY();

    int idx_str = 0;
    while (idx_str < num_str) {
        if (!(arr_str[idx_str]))
            RETURN_DUMMY();
        idx_str++;
    }

    int *arr_len = (int*)malloc(sizeof(int) * num_str);
    if (!arr_len)
        return NULL;

    int len_base = strlen(arr_str[0]);
    int idx_base = 0;
    arr_len[0] = len_base;

    int len_str;
    idx_str = 1;
    while (idx_str < num_str) {
        len_str = strlen(arr_str[idx_str]);
        if (len_str < len_base) {
            len_base = len_str;
            idx_base = idx_str;
        }
        arr_len[idx_str] = len_str;
        idx_str++;
    }

    int ofst = 0;
    char ch;
    bool should_exit = false;
    while (ofst < len_base) {
        ch = arr_str[idx_base][ofst];
        idx_str = 0;
        while (idx_str < num_str) {
            if (ch != arr_str[idx_str][ofst]) {
                should_exit = true;
                break;
            }
            idx_str++;
        }
        if (should_exit)
            break;
        ofst++;
    }

    free(arr_len);

    ofst--;
    if (ofst < 0)
        RETURN_DUMMY();

    char *prefix = (char*)malloc(sizeof(char) * (ofst + 2));
    memset(prefix, 0, sizeof(char) * (ofst + 2));
    strncpy(prefix, arr_str[idx_base], (ofst + 1));
    return prefix;
}
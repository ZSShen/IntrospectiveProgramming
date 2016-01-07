#define LEX (26)
#define BIAS(ch) (ch - 'a')

bool wordPattern(char* pattern, char* str)
{
    if (!pattern || !str)
        return true;

    char* map[LEX];
    size_t i;
    for (i = 0 ; i < LEX ; ++i)
        map[i] = NULL;

    size_t idx = 0;
    size_t len = strlen(pattern);

    /* Map for the first word. */
    char* token = strtok(str, " ");
    char ch = pattern[idx++];
    map[BIAS(ch)] = token;

    /* Map for the rest words. */
    while (true) {
        token = strtok(NULL, " ");
        if (!token || (idx == len))
            break;

        ch = pattern[idx++];
        ch = BIAS(ch);
        if (map[ch]) {
            if (strcmp(map[ch], token) != 0)
                return false;
        } else {
            /* Search the map to confirm if two characters map to
               the same word. */
            for (i = 0 ; i < LEX ; ++i) {
                if (map[i] && strcmp(map[i], token) == 0)
                    return false;
            }
            map[ch] = token;
        }
    }

    return (!token && (idx == len))? true : false;
}
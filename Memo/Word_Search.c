
bool search(char **board, int boardRowSize, int boardColSize, int row, int col,
            char *word, bool **visit)
{
    if (*word == 0)
        return true;

    bool ret = false;
    if (row > 0) {
        if (board[row - 1][col] == *word && !visit[row - 1][col]) {
            visit[row - 1][col] = true;
            ret = search(board, boardRowSize, boardColSize, row - 1, col, word + 1, visit);
            visit[row - 1][col] = false;
            if (ret)
                return true;
        }
    }
    if (row < boardRowSize - 1) {
        if (board[row + 1][col] == *word && !visit[row + 1][col]) {
            visit[row + 1][col] = true;
            ret = search(board, boardRowSize, boardColSize, row + 1, col, word + 1, visit);
            visit[row + 1][col] = false;
            if (ret)
                return true;
        }
    }
    if (col > 0) {
        if (board[row][col - 1] == *word && !visit[row][col - 1]) {
            visit[row][col - 1] = true;
            ret = search(board, boardRowSize, boardColSize, row, col - 1, word + 1, visit);
            visit[row][col - 1] = false;
            if (ret)
                return true;
        }
    }
    if (col < boardColSize - 1) {
        if (board[row][col + 1] == *word && !visit[row][col + 1]) {
            visit[row][col + 1] = true;
            ret = search(board, boardRowSize, boardColSize, row, col + 1, word + 1, visit);
            visit[row][col + 1] = false;
            if (ret)
                return true;
        }
    }

    return false;
}


void init_visit_record(bool ***p_visit, int boardRowSize, int boardColSize)
{
    int i, j;

    if (!(*p_visit)) {
        *p_visit = (bool**)malloc(sizeof(bool*) * boardRowSize);
        bool **visit = *p_visit;
        for (i = 0 ; i < boardRowSize ; i++)
            visit[i] = (bool*)malloc(sizeof(bool) * boardColSize);
    }

    bool **visit = *p_visit;
    for (i = 0 ; i < boardRowSize ; i++) {
        for (j = 0 ; j < boardColSize ; j++)
            visit[i][j] = false;
    }
}

void deinit_visit_record(bool **visit, int boardRowSize)
{
    if (visit) {
        int i;
        for (i = 0 ; i < boardRowSize ; i++)
            free(visit[i]);
        free(visit);
    }
}


bool exist(char** board, int boardRowSize, int boardColSize, char* word)
{
    if (!board || !word)
        return false;

    bool **visit = NULL;
    bool ret = false;

    int i, j;
    for (i = 0 ; i < boardRowSize ; i++) {
        for (j = 0 ; j < boardColSize ; j++) {
            if (word[0] != board[i][j])
                continue;
            init_visit_record(&visit, boardRowSize, boardColSize);
            visit[i][j] = true;
            ret = search(board, boardRowSize, boardColSize, i, j, word + 1, visit);
            if (ret)
                goto SUCC;
            visit[i][j] = false;
        }
    }

SUCC:
    deinit_visit_record(visit, boardRowSize);
    return ret;
}


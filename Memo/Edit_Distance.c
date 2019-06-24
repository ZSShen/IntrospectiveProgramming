/*
 * Formula:
 * dp[i][j] = | dp[i-1][j-1], if str1[i-1] == str2[j-1].
 *            | MIN{dp[i-1][j-1], dp[i][j-1], dp[i-1][j]} + 1, else.
 */

int minDistance(char* word1, char* word2)
{
    if (!word1 && !word2)
        return 0;
    else if (!word1)
        return strlen(word2);
    else if (!word2)
        return strlen(word1);

    int len_word1 = strlen(word1);
    int len_word2 = strlen(word2);
    int dp[len_word1 + 1][len_word2 + 1];
    int i, j, min;

    dp[0][0] = 0;
    for (i = 1 ; i <= len_word1 ; i++)
        dp[i][0] = i;
    for (j = 1 ; j <= len_word2 ; j++)
        dp[0][j] = j;

    for (i = 1 ; i <= len_word1 ; i++) {
        for (j = 1 ; j <= len_word2 ; j++) {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else {
                min = dp[i - 1][j - 1];
                if (dp[i][j - 1] < min)
                    min = dp[i][j - 1];
                if (dp[i - 1][j] < min)
                    min = dp[i - 1][j];
                dp[i][j] = min + 1;
            }
        }
    }

    return dp[len_word1][len_word2];
}
#include <iostream>
#include <string>
#include <cstring>

using namespace std;


class Solution {
public:
    void reverseWords(string &s)
    {
        int len = s.length();
        if (len == 0)
            return;

        // Firstly, flip the entire string.
        char str[len + 1];
        strcpy(str, s.c_str());
        for (int i = 0 ; i < len >> 1 ; ++i) {
            char temp = str[i];
            str[i] = str[len - i - 1];
            str[len - i - 1] = temp;
        }

        // Secondly, flip each words.
        int bgn = 0, end = 0;
        while (end < len) {
            while ((end < len) && str[end] != ' ')
                ++end;
            for (int i = 0 ; i < (end - bgn) >> 1 ; ++i) {
                char temp = str[bgn + i];
                str[bgn + i] = str[end - i - 1];
                str[end - i - 1] = temp;
            }
            ++end;
            bgn = end;
        }

        // Remove the redundant white-space between words.
        int base = 0;
        bgn = 0;
        while (base < len) {
            while ((bgn < len) && (str[bgn] == ' '))
                ++bgn;
            end = bgn;
            while ((end < len) && (str[end] != ' '))
                ++end;

            if (bgn == len)
                break;
            int idx_front = bgn;
            int idx_base = base;
            if (bgn != base) {
                while (idx_front < end) {
                    str[idx_base] = str[idx_front];
                    str[idx_front] = ' ';
                    ++idx_base;
                    ++idx_front;
                }
                base = idx_base + 1;
            } else
                base = end + 1;
            bgn = base;
        }

        // Remove the trailing white-space.
        bgn = len - 1;
        while ((bgn >= 0) && (str[bgn] == ' '))
            --bgn;
        ++bgn;

        s.assign(str, bgn);
    }
};


int main()
{
    Solution sol;

    string q1("the sky is blue");
    sol.reverseWords(q1);
    cout << q1 << '|' << q1.length() << endl;

    string q2("word");
    sol.reverseWords(q2);
    cout << q2 << '|' << q2.length() << endl;

    string q3("a b");
    sol.reverseWords(q3);
    cout << q3 << '|' << q3.length() << endl;

    string q4("a");
    sol.reverseWords(q4);
    cout << q4 << '|' << q4.length() << endl;

    string q5("a ");
    sol.reverseWords(q5);
    cout << q5 << '|' << q5.length() << endl;

    string q6(" ");
    sol.reverseWords(q6);
    cout << q6 << '|' << q6.length() << endl;

    string q7(" add     cd bba   ");
    sol.reverseWords(q7);
    cout << q7 << '|' << q7.length() << endl;

    return 0;
}

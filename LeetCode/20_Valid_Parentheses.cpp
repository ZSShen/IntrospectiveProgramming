class Solution {
public:
    bool isValid(string s) {

        std::stack<char> stk;

        int length = s.length();
        for (int i = 0 ; i < length ; ++i) {
            char ch = s[i];
            switch (ch) {
                case '(':
                case '[':
                case '{': {
                    stk.push(ch);
                    break;
                }

                case ')': {
                    if (stk.empty()) {
                        return false;
                    }
                    if (stk.top() == '(') {
                        stk.pop();
                    } else {
                        return false;
                    }
                    break;
                }
                case ']': {
                    if (stk.empty()) {
                        return false;
                    }
                    if (stk.top() == '[') {
                        stk.pop();
                    } else {
                        return false;
                    }
                    break;
                }
                case '}': {
                    if (stk.empty()) {
                        return false;
                    }
                    if (stk.top() == '{') {
                        stk.pop();
                    } else {
                        return false;
                    }
                    break;
                }
            }
        }

        return (stk.empty() == true) ? true : false;
    }
};
class Solution {
public:
    string simplifyPath(string path)
    {
        char* str = const_cast<char*>(path.c_str());
        char* token = strtok(str, "/");
        stack<char*> stk;

        while (token) {
            if (strcmp(token, "..") == 0) {
                if (!stk.empty())
                    stk.pop();
            }
            else if (strcmp(token, ".") != 0)
                stk.push(token);
            token = strtok(NULL, "/");
        }

        if (stk.empty())
            return string("/");

        vector<char*> vec;
        while (!stk.empty()) {
            token = stk.top();
            vec.push_back(token);
            stk.pop();
        }

        stringstream str_stream;
        int idx = vec.size() - 1;
        while (idx >= 0) {
            str_stream << '/';
            str_stream << vec[idx];
            --idx;
        }

        return str_stream.str();
    }
};
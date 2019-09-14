class Solution {
public:
    /**
     * @param path: the original path
     * @return: the simplified path
     */
    string simplifyPath(string &path) {
        // write your code here

        std::vector<std::string> tokens;

        int n = path.length();
        int i = 1;

        while (i < n) {

            if (path[i] != '/') {
                std::string token;

                while (i < n && path[i] != '/') {
                    token.push_back(path[i]);
                    ++i;
                }

                if (token == "..") {
                    if (!tokens.empty()) {
                        tokens.pop_back();
                    }
                    continue;
                }

                if (token != ".") {
                    tokens.emplace_back(std::move(token));
                }
                continue;
            }

            while (i < n && path[i] == '/') {
                ++i;
            }
        }

        std::string ans;
        for (const auto& token : tokens) {
            ans.push_back('/');
            ans += token;
        }

        return !ans.empty() ? ans : "/";
    }
};
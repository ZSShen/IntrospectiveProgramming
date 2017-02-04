class Solution {
public:
    string decodeString(string s) {
        const char* scan = s.c_str();
        return std::move(decodeString(scan));
    }

private:
    enum {
        RAW_DATA,
        REPEAT_TIME,
        BEGIN_ENCODE,
        END_ENCODE
    };

private:
    std::string decodeString(const char*& scan) {
        std::stringstream result;
        char state = RAW_DATA;
        char ch;
        int repeat;

        while ((ch = *scan) != '\0') {
            switch (state) {
                case RAW_DATA: {
                    if (ch >= 'a' && ch <= 'z') {
                        result << ch;
                    } else if (ch >= '0' && ch <= '9') {
                        repeat = ch - '0';
                        state = REPEAT_TIME;
                    } else if (ch == ']') {
                        state = END_ENCODE;
                    }
                    ++scan;
                    break;
                }
                case REPEAT_TIME: {
                    if (ch >= '0' && ch <= '9') {
                        repeat *= 10;
                        repeat += ch - '0';
                    } else if (ch == '[') {
                        state = BEGIN_ENCODE;
                    }
                    ++scan;
                    break;
                }
                case BEGIN_ENCODE: {
                    auto&& decode = decodeString(scan);
                    for (int i = 0 ; i < repeat ; ++i) {
                        result << decode;
                    }
                    state = RAW_DATA;
                    break;
                }
                case END_ENCODE: {
                    return std::move(result.str());
                }
            }
        }

        return std::move(result.str());
    }
};
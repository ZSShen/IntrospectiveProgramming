class Solution {
public:
    string validIPAddress(string IP) {

        auto pos = IP.find('.');
        if (pos != std::string::npos) {
            return isV4(IP) ? "IPv4" : "Neither";
        }

        pos = IP.find(':');
        if (pos != std::string::npos) {
            return isV6(IP) ? "IPv6" : "Neither";
        }

        return "Neither";
    }

private:
    std::string getToken(const auto& str, int& bgn, int end, char delm) {

        if (bgn >= end) {
            return "";
        }

        int base = bgn;
        while (bgn < end && str[bgn] != delm) {
            ++bgn;
        }

        auto token = str.substr(base, bgn - base);
        ++bgn;
        return token;
    }

    bool validV4Token(const auto& str) {

        if (str.length() > 3) {
            return false;
        }

        if (str.length() > 1 && str[0] == '0') {
            return false;
        }

        for (char ch : str) {
            if (!('0' <= ch && ch <= '9')) {
                return false;
            }
        }
        return true;
    }

    bool validV6Token(const auto& str) {

        if (str.length() > 4) {
            return false;
        }

        for (char ch : str) {
            if (!(('0' <= ch && ch <= '9') ||
                  ('a' <= ch && ch <= 'f') ||
                  ('A' <= ch && ch <= 'F') )) {
                return false;
            }
        }
        return true;
    }

    bool isV4(const auto& ip) {

        int count = 0;
        int bgn = 0, end = ip.length();

        if (ip[end - 1] == '.') {
            return false;
        }

        while (true) {
            auto token = getToken(ip, bgn, end, '.');

            if (!validV4Token(token) || token.empty() || count > 4) {
                break;
            }

            int value = std::stoi(token);
            if (!(value >= 0 && value <= 255)) {
                break;
            }

            ++count;
        }

        return count == 4;
    }

    bool isV6(const auto& ip) {

        int count = 0;
        int bgn = 0, end = ip.length();

        if (ip[end - 1] == ':') {
            return false;
        }

        while (true) {
            auto token = getToken(ip, bgn, end, ':');

            if (!validV6Token(token) || token.empty() || count > 8) {
                break;
            }

            int value = std::stoi(token, 0, 16);
            if (!(value >= 0 && value <= 65535)) {
                break;
            }

            ++count;
        }

        return count == 8;
    }
};
class Solution {
public:
    /**
     * @param n: Given a decimal number that is passed in as a string
     * @return: A string
     */
    string binaryRepresentation(string &n) {
        // write your code here

        /**
         *  0.72
         *  1.44  -> 1
         *
         *  0.44
         *  0.88  -> 0
         *
         *  0.88
         *  1.76  -> 1
         *
         *  0.76
         *  1.52  -> 1
         *
         *  0.52
         *  1.04  -> 4
         */

        auto pos = n.find('.');
        if (pos == std::string::npos) {
            return convertInteger(n);
        } else {
            ++pos;
            int len = n.length();

            auto fraction = n.substr(pos, len - pos);
            fraction = convertFraction(fraction);
            if (fraction == "ERROR") {
                return "ERROR";
            }

            auto integer = n.substr(0, pos - 1);
            integer = convertInteger(integer);

            return (fraction == "") ? integer : integer + "." + fraction;
        }
    }

private:
    std::string convertFraction(const std::string& str) {

        auto num = std::stold("." + str);
        if (num == 0) {
            return "";
        }

        int round = 0;
        int limit = 32;
        std::string rep;

        while (round < limit) {
            num *= 2;
            if (num >= 1.0) {
                rep.push_back('1');
                num -= 1;
                if (num == 0.0) {
                    break;
                }
            } else {
                rep.push_back('0');
            }

            ++round;
        }

        return (round == limit) ? "ERROR" : rep;
    }


    std::string convertInteger(const std::string& str) {

        auto num = std::stoll(str);
        if (num == 0) {
            return "0";
        }

        std::string rep;
        while (num > 0) {
            int bit = num % 2;
            num /= 2;
            if (bit == 0) {
                rep.push_back('0');
            } else {
                rep.push_back('1');
            }
        }

        std::reverse(rep.begin(), rep.end());
        return rep;
    }
};
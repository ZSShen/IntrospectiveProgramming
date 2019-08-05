class Solution {
public:
    /**
     * @param n: Given a decimal number that is passed in as a string
     * @return: A string
     */
    string binaryRepresentation(string &n) {
        // write your code here

        /**
         * The strategy to handle the fractional part.
         *
         * e.g: 0.125 (demical)
         *
         *      0.25  -> 0
         *
         *      0.5   -> 0
         *
         *      1.0   -> 1
         *      0.0   -> end
         *
         *      0.001 (binary)
         */

        auto pos = n.find('.');
        if (pos == std::string::npos) {
            return convertIntegralPart(n);
        }

        auto int_part_dec = n.substr(0, pos);
        auto fac_part_dec = n.substr(pos, n.length() - pos);
        auto int_part_bin = convertIntegralPart(int_part_dec);
        auto fac_part_bin = convertFractionalPart(fac_part_dec);

        if (fac_part_bin == "ERROR") {
            return "ERROR";
        }
        if (fac_part_bin.empty()) {
            return int_part_bin;
        }

        return int_part_bin + "." + fac_part_bin;
    }

private:
    std::string convertIntegralPart(const std::string& str) {

        std::string res;

        int n = std::stoi(str);
        while (n > 0) {
            div_t temp = std::div(n, 2);
            n = temp.quot;

            if (temp.rem == 0) {
                res.push_back('0');
            } else {
                res.push_back('1');
            }
        }

        if (res.empty()) {
            res.push_back('0');
        }

        std::reverse(res.begin(), res.end());
        return res;
    }

    std::string convertFractionalPart(const std::string& str) {

        int max_len = 32;
        int len = 0;
        std::string res;

        double n = std::stod(str);
        while (n > 0) {
            n *= 2;

            if (n < 1) {
                res.push_back('0');
            }  else {
                res.push_back('1');
                n -= 1;
            }

            ++len;
            if (len > max_len) {
                return "ERROR";
            }
        }

        return res;
    }
};
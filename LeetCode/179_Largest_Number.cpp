class Solution {
public:
    string largestNumber(vector<int>& nums) {

        std::unordered_map<int, int> degrees;
        for (int num : nums) {
            degrees[num] = (num > 0) ?
                static_cast<int>(floor(log10(num))) + 1 : 1;
        }

        std::sort(nums.begin(), nums.end(),
            [&] (int src, int dst) -> bool {

                long src_lead = src * static_cast<long>(pow(10, degrees[dst])) + dst;
                long dst_lead = dst * static_cast<long>(pow(10, degrees[src])) + src;

                return src_lead > dst_lead;
            });

        std::string result;
        for (int num : nums) {
            result += std::to_string(num);
        }

        return (result[0] == '0') ? "0" : result;

        /*
        std::vector<std::string> str_nums;
        for (int num : nums) {
            str_nums.push_back(std::to_string(num));
        }

        std::sort(str_nums.begin(), str_nums.end(),
            [] (const std::string& src,
                const std::string& dst) -> bool {

                auto src_lead = src + dst;
                auto dst_lead = dst + src;
                return src_lead > dst_lead;
            });

        std::string result;
        for (const auto& str : str_nums) {
            result += str;
        }

        return (result[0] == '0') ? "0" : result;
        */
    }
};
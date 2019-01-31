class Solution {
public:
    string addBinary(string a, string b) {

        int len_a = a.length();
        int len_b = b.length();
        int len_max = std::max(len_a, len_b) + 1;

        std::vector<int> nums_a(len_max, 0);
        int pivot = len_max - len_a;
        for (char ch : a) {
            nums_a[pivot++] = static_cast<int>(ch - '0');
        }

        std::vector<int> nums_b(len_max, 0);
        pivot = len_max - len_b;
        for (char ch : b) {
            nums_b[pivot++] = static_cast<int>(ch - '0');
        }

        for (int i = len_max - 1 ; i > 0 ; --i) {
            nums_a[i] += nums_b[i];
            if (nums_a[i] > 1) {
                nums_a[i] -= 2;
                nums_a[i - 1] += 1;
            }
        }

        std::string sum;
        pivot = 0;
        while (nums_a[pivot] == 0) {
            ++pivot;
        }
        while (pivot < len_max) {
            sum.push_back(static_cast<char>(nums_a[pivot] + '0'));
            ++pivot;
        }

        return (sum.length() > 0)? sum : "0";
    }
};
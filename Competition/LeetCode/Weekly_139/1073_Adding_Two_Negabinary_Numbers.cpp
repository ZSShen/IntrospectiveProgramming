class Solution {
public:
    vector<int> addNegabinary(vector<int>& A, vector<int>& B) {

        std::vector<int> ans;
        int carry = 0, i = A.size() - 1, j = B.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) {
                carry += A[i--];
            }
            if (j >= 0) {
                carry += B[j--];
            }
            ans.push_back(carry & 1);
            carry = -(carry >> 1);
        }

        while (ans.size() > 1 && ans.back() == 0) {
            ans.pop_back();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
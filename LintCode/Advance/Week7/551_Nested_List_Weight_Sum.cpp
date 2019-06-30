/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

struct Record {
    std::vector<NestedInteger>::iterator bgn;
    std::vector<NestedInteger>::iterator end;
    int weight;

    Record(const auto& bgn, const auto& end, int weight)
      : bgn(bgn), end(end), weight(weight)
    { }
};

class Solution {
public:
    int depthSum(vector<NestedInteger>& list) {
        // Write your code here

        std::stack<Record> stack;
        stack.push(Record(list.begin(), list.end(), 1));

        int sum = 0;

        while (!stack.empty()) {
            auto top = stack.top();
            auto& bgn = top.bgn;
            auto& end = top.end;
            int weight = top.weight;
            stack.pop();

            while (bgn != end) {
                if (bgn->isInteger()) {
                    sum += bgn->getInteger() * weight;
                    ++bgn;
                } else {
                    auto& list =
                        const_cast<std::vector<NestedInteger>&>(bgn->getList());
                    ++bgn;
                    stack.push(Record(bgn, end, weight));
                    stack.push(Record(list.begin(), list.end(), weight + 1));
                    break;
                }
            }
        }

        return sum;
    }
};

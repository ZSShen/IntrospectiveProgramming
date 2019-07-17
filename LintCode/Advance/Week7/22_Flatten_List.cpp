// Recursive Solution

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
class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(const vector<NestedInteger> &list) {
        // Write your code here

        std::vector<int> ans;

        for (auto& elem : list) {
            if (elem.isInteger()) {
                ans.push_back(elem.getInteger());
            } else {
                auto rtn = flatten(elem.getList());
                for (num : rtn) {
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};


// Non-recursive Solution

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
class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        // Write your code here

        std::vector<int> ans;

        std::stack<
            std::pair<
                std::vector<NestedInteger>::iterator,
                std::vector<NestedInteger>::iterator>> stk;

        if (!nestedList.empty()) {
            stk.push(std::make_pair(nestedList.begin(), nestedList.end()));
        }

        while (!stk.empty()) {

            auto top = stk.top();
            stk.pop();

            auto& bgn = top.first;
            auto& end = top.second;

            while (bgn != end) {
                if (bgn->isInteger()) {
                    ans.push_back(bgn->getInteger());
                    ++bgn;
                } else {
                    auto& list =
                        const_cast<std::vector<NestedInteger>&>(bgn->getList());

                    ++bgn;
                    if (bgn != end) {
                        stk.push(std::make_pair(bgn, end));
                    }

                    if (!list.empty()) {
                        stk.push(std::make_pair(list.begin(), list.end()));
                    }
                    break;
                }
            }
        }

        return ans;
    }
};
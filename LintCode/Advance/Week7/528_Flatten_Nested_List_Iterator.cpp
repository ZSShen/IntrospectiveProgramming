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
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.

        if (!nestedList.empty()) {
            stk.push(std::make_pair(nestedList.begin(), nestedList.end()));
        }
    }

    // @return {int} the next element in the iteration
    int next() {
        // Write your code here

        return cache;
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        // Write your code here

        while (!stk.empty()) {

            auto top = stk.top();
            stk.pop();
            auto& bgn = top.first;
            auto& end = top.second;

            if (bgn->isInteger()) {
                cache = bgn->getInteger();

                ++bgn;
                if (bgn != end) {
                    stk.push(std::make_pair(bgn, end));
                }

                return true;
            }

            auto& list =
                const_cast<std::vector<NestedInteger>&>(bgn->getList());

            ++bgn;
            if (bgn != end) {
                stk.push(std::make_pair(bgn, end));
            }

            if (!list.empty()) {
                stk.push(std::make_pair(list.begin(), list.end()));
            }
        }

        return false;
    }

private:
    std::stack<
        std::pair<
            std::vector<NestedInteger>::iterator,
            std::vector<NestedInteger>::iterator>> stk;
    int cache;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */
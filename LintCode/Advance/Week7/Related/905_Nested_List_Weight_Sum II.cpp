

struct Record {

    int depth;
    std::vector<NestedInteger>::iterator bgn, end;

    Record(int depth, auto&& bgn, auto&& end)
      : depth(depth), bgn(bgn), end(end)
    { }
};


struct Element {
    int num, weight;

    Element(int num, int weight)
      : num(num), weight(weight)
    { }
};


class Solution {
public:
    /**
     * @param nestedList: a list of NestedInteger
     * @return: the sum
     */
    int depthSumInverse(vector<NestedInteger> nestedList) {
        // Write your code here.

        /**
         *  [[1, 1], 2, [1, 1]]
         *
         *  [1, 2], [1, 2], [2, 1], [1, 2], [1, 2]
         *
         *  => adjusted weight = maximum depth - original weight + 1
         *
         *  [1, 1], [1, 1], [2, 2], [1, 1], [1, 1]
         *
         *  => generate the final sum
         */

        if (nestedList.empty()) {
            return 0;
        }

        std::stack<Record> stk;
        stk.push(Record(1, nestedList.begin(), nestedList.end()));

        int max_depth = 0;
        std::vector<Element> cache;

        while (!stk.empty()) {

            auto top = stk.top();
            stk.pop();

            int depth = top.depth;
            max_depth = std::max(max_depth, depth);

            auto& bgn = top.bgn;
            auto& end = top.end;

            while (bgn != end) {

                if (bgn->isInteger()) {
                    cache.emplace_back(bgn->getInteger(), depth);
                    ++bgn;
                } else {
                    auto& list =
                        const_cast<std::vector<NestedInteger>&>(bgn->getList());

                    ++bgn;
                    if (bgn != end) {
                        stk.push(Record(depth, std::move(bgn), std::move(end)));
                    }

                    if (!list.empty()) {
                        stk.push(Record(depth + 1, list.begin(), list.end()));
                    }

                    break;
                }
            }
        }

        int sum = 0;
        for (auto& elem : cache) {
            sum += elem.num * (max_depth - elem.weight + 1);
        }

        return sum;
    }
};
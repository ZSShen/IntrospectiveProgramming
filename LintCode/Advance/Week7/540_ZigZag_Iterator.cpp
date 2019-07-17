class ZigzagIterator {
public:
    /*
    * @param v1: A 1d vector
    * @param v2: A 1d vector
    */ZigzagIterator(vector<int>& v1, vector<int>& v2)
      : turn(0) {
        // do intialization if necessary

        bgns[0] = v1.begin();
        bgns[1] = v2.begin();

        ends[0] = v1.end();
        ends[1] = v2.end();
    }

    /*
     * @return: An integer
     */
    int next() {
        // write your code here

        if (bgns[0] == ends[0]) {
            int elem = *bgns[1];
            ++bgns[1];
            return elem;
        }

        if (bgns[1] == ends[1]) {
            int elem = *bgns[0];
            ++bgns[0];
            return elem;
        }

        int elem = *bgns[turn];
        ++bgns[turn];
        turn = (turn + 1) % 2;
        return elem;
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        // write your code here

        return (bgns[0] != ends[0]) || (bgns[1] != ends[1]);
    }

private:
    int turn;
    std::vector<int>::iterator bgns[2];
    std::vector<int>::iterator ends[2];
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator solution(v1, v2);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */


class ZigzagIterator {
public:
    /*
    * @param v1: A 1d vector
    * @param v2: A 1d vector
    */ZigzagIterator(vector<int>& v1, vector<int>& v2)
      : bgn_first(v1.begin()),
        bgn_second(v2.begin()),
        end_first(v1.end()),
        end_second(v2.end()),
        turn(Turn::FIRST) {
        // do intialization if necessary
    }

    /*
     * @return: An integer
     */
    int next() {
        // write your code here

        return cache;
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        // write your code here

        if (bgn_first != end_first && bgn_second != end_second) {
            if (turn == Turn::FIRST) {
                cache = *bgn_first;
                ++bgn_first;
                turn = Turn::SECOND;
            } else {
                cache = *bgn_second;
                ++bgn_second;
                turn = Turn::FIRST;
            }
            return true;
        }

        if (bgn_first != end_first) {
            cache = *bgn_first;
            ++bgn_first;
            return true;
        }

        if (bgn_second != end_second) {
            cache = *bgn_second;
            ++bgn_second;
            return true;
        }

        return false;
    }

private:
    std::vector<int>::iterator bgn_first, bgn_second, end_first, end_second;
    char turn;
    int cache;

    enum Turn {
        FIRST,
        SECOND
    };
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator solution(v1, v2);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */
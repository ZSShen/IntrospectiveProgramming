class ZigzagIterator2 {
public:
    /*
    * @param vecs: a list of 1d vectors
    */ZigzagIterator2(vector<vector<int>>& vecs)
      : turn(0),
        total(0),
        vecs(vecs) {
        // do intialization if necessary

        for (auto& vec : vecs) {
            if (!vec.empty()) {
                bgns.push_back(vec.begin());
                ends.push_back(vec.end());
                ++total;
            }
        }
    }

    /*
     * @return: An integer
     */
    int next() {
        // write your code here

        int elem = *bgns[turn];
        ++bgns[turn];

        if (bgns[turn] == ends[turn]) {
            bgns.erase(bgns.begin() + turn);
            ends.erase(ends.begin() + turn);

            --total;
            if (total > 0) {
                turn = turn % total;
            }
        } else {
            turn = (turn + 1) % total;
        }

        return elem;
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        // write your code here

        return total > 0;
    }

private:
    int turn, total;

    std::vector<std::vector<int>::iterator> bgns;
    std::vector<std::vector<int>::iterator> ends;

    std::vector<std::vector<int>> vecs;
};

/**
 * Your ZigzagIterator2 object will be instantiated and called as such:
 * ZigzagIterator2 solution(vecs);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */


class ZigzagIterator2 {
public:
    /*
    * @param vecs: a list of 1d vectors
    */ZigzagIterator2(vector<vector<int>>& vecs)
      : total(0), turn(0) {
        // do intialization if necessary

        for (auto& vec : vecs) {
            if (!vec.empty()) {
                bgns.emplace_back(vec.begin());
                ends.emplace_back(vec.end());
                ++total;
            }
        }
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

        if (total == 0) {
            return false;
        }

        cache = *bgns[turn];
        ++bgns[turn];

        if (bgns[turn] == ends[turn]) {
            bgns.erase(bgns.begin() + turn);
            ends.erase(ends.begin() + turn);

            --total;
            if (total > 0) {
                turn = turn % total;
            }
        } else {
            turn = (turn + 1) % total;
        }

        return true;
    }

private:
    std::vector<vector<int>::iterator> bgns;
    std::vector<vector<int>::iterator> ends;

    int total;
    int turn;

    int cache;
};

/**
 * Your ZigzagIterator2 object will be instantiated and called as such:
 * ZigzagIterator2 solution(vecs);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */
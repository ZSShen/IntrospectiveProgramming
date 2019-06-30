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
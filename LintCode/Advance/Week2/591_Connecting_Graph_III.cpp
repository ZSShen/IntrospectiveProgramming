class ConnectingGraph3 {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */

    ConnectingGraph3(int n)
      : count(n),
        parents(std::vector<int>(n + 1)) {

        for (int i = 1 ; i <= n ; ++i) {
            parents[i] = i;
        }
    }


    void connect(int a, int b) {
        // write your code here

        merge(a, b);
    }

    /**
     * @return: An integer
     */
    int query() {
        // write your code here

        return count;
    }

private:

    int find(int x) {

        if (parents[x] == x) {
            return x;
        }

        parents[x] = find(parents[x]);
        return parents[x];
    }


    void merge(int x, int y) {

        int px = find(x);
        int py = find(y);

        if (px != py) {
            parents[px] = py;
            --count;
        }
    }


    int count;
    std::vector<int> parents;
};
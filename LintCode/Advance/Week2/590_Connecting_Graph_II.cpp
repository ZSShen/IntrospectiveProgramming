class ConnectingGraph2 {
public:
    /*
    * @param n: An integer
    */ConnectingGraph2(int n)
      : sizes(std::vector<int>(n + 1)),
        parents(std::vector<int>(n + 1)) {
        // do intialization if necessary

        for (int i = 1 ; i <= n ; ++i) {
            sizes[i] = 1;
            parents[i] = i;
        }
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        // write your code here

        merge(a, b);
    }

    /*
     * @param a: An integer
     * @return: An integer
     */
    int query(int a) {
        // write your code here

        return sizes[find(a)];
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
            sizes[py] += sizes[px];
        }
    }


    std::vector<int> sizes;
    std::vector<int> parents;
};
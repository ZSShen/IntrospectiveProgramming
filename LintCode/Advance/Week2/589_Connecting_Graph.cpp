class ConnectingGraph {
public:
    /*
    * @param n: An integer
    */ConnectingGraph(int n)
      : parent(std::vector<int>(n + 1)) {
        // do intialization if necessary

        for (int i = 1 ; i <= n ; ++i) {
            list.insert(std::make_pair(i, std::vector<int>()));
            parent[i] = i;
        }
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        // write your code here

        list[a].push_back(b);
        list[b].push_back(a);

        merge(a, b);
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: A boolean
     */
    bool query(int a, int b) {
        // write your code here

        return find(a) == find(b);
    }

private:

    int find(int x) {

        if (parent[x] == x) {
            return x;
        }

        parent[x] = find(parent[x]);
        return parent[x];
    }

    void merge(int x, int y) {

        int p_x = find(x);
        int p_y = find(y);

        if (p_x != p_y) {
            parent[p_x] = p_y;
        }
    }

    std::unordered_map<int, std::vector<int>> list;
    std::vector<int> parent;
};
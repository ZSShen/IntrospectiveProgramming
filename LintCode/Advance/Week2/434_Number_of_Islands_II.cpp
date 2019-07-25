/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class UnionFind {
public:
    UnionFind()
      : count(0)
    { }

    void add(int x) {

        ++count;
        parents[x] = x;
    }

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

    int query() {
        return count;
    }

private:
    int count;
    std::unordered_map<int, int> parents;
};


class Solution {
public:
    Solution()
      : directs({
          {1, 0},
          {-1, 0},
          {0, 1},
          {0, -1}
      })
    { }

    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        // write your code here

        /**
         *  0 0 0 0 0
         *  0 0 0 0 0
         *  0 0 0 0 0
         *  0 0 0 0 0
         *
         *  (1, 1)
         *  0 0 0 0 0
         *  0 1 0 0 0  1 island
         *  0 0 0 0 0
         *  0 0 0 0 0
         *
         *  (0, 1)
         *  0 1 0 0 0
         *  0 1 0 0 0  1 island
         *  0 0 0 0 0
         *  0 0 0 0 0
         *
         *  (3, 3)
         *  0 1 0 0 0
         *  0 1 0 0 0  2 island
         *  0 0 0 0 0
         *  0 0 0 1 0
         *
         *  (3, 4)
         *  0 1 0 0 0
         *  0 1 0 0 0  2 island
         *  0 0 0 0 0
         *  0 0 0 1 1
         *
         */

        UnionFind sets;

        std::vector<std::vector<int>> sea(n, std::vector<int>(m, 0));
        std::vector<int> ans;

        for (const auto& point : operators) {
            int x = point.x;
            int y = point.y;

            if (sea[x][y] == 1) {
                ans.push_back(sets.query());
                continue;
            }

            // Create a new island.
            sea[x][y] = 1;
            int id = getIslandId(m, x, y);
            sets.add(id);

            // Try to merge the new island with its neighbors.
            for (const auto& direct : directs) {
                int nx = x + direct[0];
                int ny = y + direct[1];

                if (!(nx >= 0 && nx < n && ny >= 0 && ny < m)) {
                    continue;
                }

                if (sea[nx][ny] == 0) {
                    continue;
                }

                int nid = getIslandId(m, nx, ny);
                sets.merge(id, nid);
            }

            ans.push_back(sets.query());
        }

        return ans;
    }

private:
    int getIslandId(int m, int r, int c) {
        return r * m + c;
    }

private:
    std::vector<std::vector<int>> directs;
};


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */


class DisjointSet {
public:
    DisjointSet()
      : count(0)
    { }

    void add(int x) {
        parent[x] = x;
        ++count;
    }

    int find(int x) {

        if (parent[x] == x) {
            return x;
        }

        parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {

        int px = find(x);
        int py = find(y);

        if (px != py) {
            parent[px] = py;
            --count;
        }
    }

    int getNumberOfSets() {
        return count;
    }

private:
    int count;
    std::unordered_map<int, int> parent;
};


class Solution {
public:
    Solution()
      : directs({{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
    { }

    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        // write your code here

        /**
         *  00000       00000       01000        01000        01000
         *  00000  =>   01000   =>  01000   =>   01000   =>   01000
         *  00000       00000       00000        00000        00000
         *  00000       00000       00000        00010        00011
         *
         *           1 (1, 1)    2 (0, 1)     1 (1, 1)     1 (1, 1)
         *                       1 (1, 1)       (0, 1)       (0, 1)
         *
         *                       1 (1, 1)     3 (3, 3)     3 (3, 3)
         *                         (0, 1)                    (3, 4)
         */

        std::vector<int> ans;
        std::vector<std::vector<int>> grid(n, std::vector<int>(m, 0));
        DisjointSet set;

        for (const auto& op : operators) {
            int x = op.x;
            int y = op.y;

            // Should avoid the dpulicated operations.
            if (grid[x][y] != 0) {
                ans.push_back(set.getNumberOfSets());
                continue;
            }

            int id = generateId(m, x, y);
            set.add(id);
            grid[x][y] = id;

            for (const auto& direct : directs) {
                int nx = x + direct[0];
                int ny = y + direct[1];

                if (!(nx >=0 && ny >= 0 && nx < n && ny < m) ||
                    grid[nx][ny] == 0) {
                    continue;
                }

                set.unite(id, grid[nx][ny]);
            }

            ans.push_back(set.getNumberOfSets());
        }

        return ans;
    }

private:
    int generateId(int m, int x, int y) {
        return m * x + y + 1;
    }

    std::vector<std::vector<int>> directs;
};
/**
 * Definition for a Connection.
 * class Connection {
 * public:
 *   string city1, city2;
 *   int cost;
 *   Connection(string& city1, string& city2, int cost) {
 *       this->city1 = city1;
 *       this->city2 = city2;
 *       this->cost = cost;
 * }
 */


class DisjointSet {
public:
    DisjointSet(int n)
      : parents(std::vector<int>(n)) {

        for (int i = 0 ; i < n ; ++i) {
            parents[i] = i;
        }
    }

    int find(int id) {
        if (id == parents[id]) {
            return id;
        }

        parents[id] = find(parents[id]);
        return parents[id];
    }

    void unite(int x, int y) {

        int rx = find(x);
        int ry = find(y);

        if (rx != ry) {
            parents[rx] = ry;
        }
    }

private:
    std::vector<int> parents;
};


class Solution {
public:
    /**
     * @param connections given a list of connections include two cities and cost
     * @return a list of connections from results
     */
    vector<Connection> lowestCost(vector<Connection>& connections) {
        // Write your code here

        std::unordered_map<std::string, int> name_2_id;

        int id = 0;
        for (const auto& connection : connections) {
            const auto& src = connection.city1;
            const auto& dst = connection.city2;

            if (name_2_id.count(src) == 0) {
                name_2_id[src] = id;
                ++id;
            }
            if (name_2_id.count(dst) == 0) {
                name_2_id[dst] = id;
                ++id;
            }
        }

        std::sort(connections.begin(), connections.end(),
            [] (const Connection& lhs, const Connection& rhs) {

                if (lhs.cost == rhs.cost) {
                    int order = lhs.city1.compare(rhs.city1);
                    if (order == 0) {
                        return lhs.city2 < rhs.city2;
                    }
                    return order < 0;
                }
                return lhs.cost < rhs.cost;
            });

        DisjointSet ds(id);

        std::vector<Connection> ans;

        for (const auto& connection : connections) {
            const auto& src_city = connection.city1;
            const auto& dst_city = connection.city2;

            int src_id = name_2_id[src_city];
            int dst_id = name_2_id[dst_city];

            if (ds.find(src_id) != ds.find(dst_id)) {
                ds.unite(src_id, dst_id);
                ans.push_back(connection);
            }
        }

        return (ans.size() == id - 1) ? ans : std::vector<Connection>();
    }
};


/**
 * Definition for a Connection.
 * class Connection {
 * public:
 *   string city1, city2;
 *   int cost;
 *   Connection(string& city1, string& city2, int cost) {
 *       this->city1 = city1;
 *       this->city2 = city2;
 *       this->cost = cost;
 * }
 */


class DisjointSet {
public:
    DisjointSet(int n)
      : parent(std::vector<int>(n)) {

        for (int i = 0 ; i < n ; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {

        if (x == parent[x]) {
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
        }
    }

    bool is_same(int x, int y) {

        int px = find(x);
        int py = find(y);

        return px == py;
    }

private:
    std::vector<int> parent;
};


class Solution {
public:
    /**
     * @param connections given a list of connections include two cities and cost
     * @return a list of connections from results
     */
    vector<Connection> lowestCost(vector<Connection>& connections) {
        // Write your code here

        std::unordered_map<std::string, int> name_2_id;

        int id = 0;
        for (const auto& edge : connections) {
            const auto& src = edge.city1;
            const auto& dst = edge.city2;

            if (name_2_id.count(src) == 0) {
                name_2_id[src] = id;
                ++id;
            }
            if (name_2_id.count(dst) == 0) {
                name_2_id[dst] = id;
                ++id;
            }
        }

        DisjointSet set(id);

        std::sort(connections.begin(), connections.end(),
            [](const auto& lhs, const auto& rhs) {
            if (lhs.cost == rhs.cost) {
                int order = lhs.city1.compare(rhs.city1);
                if (order == 0) {
                    return lhs.city2 < rhs.city2;
                }
                return order < 0;
            }
            return lhs.cost < rhs.cost;
        });


        std::vector<Connection> ans;
        for (auto& edge : connections) {
            auto& src = edge.city1;
            auto& dst = edge.city2;

            int src_id = name_2_id[src];
            int dst_id = name_2_id[dst];

            if (set.is_same(src_id, dst_id)) {
                continue;
            }
            set.unite(src_id, dst_id);

            ans.push_back(Connection(src, dst, edge.cost));
        }

        return (ans.size() == id - 1) ? ans : std::vector<Connection>();
    }
};
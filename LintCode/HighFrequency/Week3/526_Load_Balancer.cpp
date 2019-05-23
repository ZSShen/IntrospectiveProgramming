class LoadBalancer {
public:
    LoadBalancer() {
        // do intialization if necessary
        srand(time(nullptr));
    }

    /*
     * @param server_id: add a new server to the cluster
     * @return: nothing
     */
    void add(int server_id) {
        // write your code here

        map[server_id] = vec.size();
        vec.push_back(server_id);
    }

    /*
     * @param server_id: server_id remove a bad server from the cluster
     * @return: nothing
     */
    void remove(int server_id) {
        // write your code here

        int index = map[server_id];
        int size = vec.size();

        vec[index] = vec[size - 1];
        vec.pop_back();

        map[vec[index]] = index;
        map.erase(server_id);
    }

    /*
     * @return: pick a server in the cluster randomly with equal probability
     */
    int pick() {
        // write your code here

        int index = random() % vec.size();
        return vec[index];
    }

private:
    std::vector<int> vec;
    std::unordered_map<int, int> map;
};
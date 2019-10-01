class Solution {
public:
    /**
     * @param n: a integer
     * @param flights: a 2D array
     * @param src: a integer
     * @param dst: a integer
     * @param K: a integer
     * @return: return a integer
     */
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
        // write your code here

        std::vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0 ; i <= K ; ++i) {
            std::vector<bool> used(n, false);

            for (const auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];

                if (used[u]) {
                    continue;
                }

                long sum = static_cast<long>(dist[u]) + w;
                if (sum < dist[v]) {
                    dist[v] = sum;
                    used[v] = true;
                }
            }
        }

        return (dist[dst] != INT_MAX) ? dist[dst] : -1;
    }
};
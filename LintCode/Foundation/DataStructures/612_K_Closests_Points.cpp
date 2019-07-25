/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

struct Record {
    int id;
    double dist;
    int x;
    int y;

    Record(int id, double dist, int x, int y)
      : id(id), dist(dist), x(x), y(y)
    { }
};


struct RecordCompare {

    bool operator() (const auto& lhs, const auto& rhs) {
        if (lhs.dist == rhs.dist) {
            if (lhs.x == rhs.y) {
                return lhs.y < rhs.y;
            }
            return lhs.x < rhs.x;
        }
        return lhs.dist < rhs.dist;
    }
};


class Solution {
public:
    /**
     * @param points: a list of points
     * @param origin: a point
     * @param k: An integer
     * @return: the k closest points
     */
    vector<Point> kClosest(vector<Point> &points, Point &origin, int k) {
        // write your code here

        int n = points.size();
        if (n == 0) {
            return {};
        }

        std::priority_queue<Record, std::vector<Record>, RecordCompare> queue;
        for (int i = 0 ; i < n ; ++i) {
            const auto& point = points[i];

            int x = point.x;
            int y = point.y;
            double dist = sqrt(pow(x - origin.x, 2) + pow(y - origin.y, 2));

            queue.push(Record(i, dist, x, y));
            if (queue.size() > k) {
                queue.pop();
            }
        }

        std::vector<Point> ans;
        while (!queue.empty()) {
            auto rec = queue.top();
            queue.pop();
            ans.push_back(points[rec.id]);
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
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
    int x;
    int y;
    double dist;

    Record(int x, int y, double dist)
        : x(x), y(y), dist(dist)
    { }
};


struct RecordCompare {
    bool operator() (const Record& src, const Record& dst) {
        if (src.dist < dst.dist) {
            return false;
        }
        if (src.dist > dst.dist) {
            return true;
        }

        if (src.x < dst.x) {
            return false;
        }
        if (src.x > dst.x) {
            return true;
        }

        if (src.y < dst.y) {
            return false;
        }
        if (src.y > dst.y) {
            return true;
        }
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

        std::priority_queue<Record, std::vector<Record>, RecordCompare> queue;
        for (const auto& point : points) {
            int x_diff = point.x - origin.x;
            int y_diff = point.y - origin.y;
            double dist = sqrt(x_diff * x_diff + y_diff * y_diff);
            queue.push(Record(point.x, point.y, dist));
        }

        std::vector<Point> ans;
        for (int i = 0 ; i < k ; ++i) {
            auto& record = queue.top();
            ans.push_back(Point(record.x, record.y));
            queue.pop();
        }

        return ans;
    }
};
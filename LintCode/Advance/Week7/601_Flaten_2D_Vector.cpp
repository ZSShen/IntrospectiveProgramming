class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d)
      : r(0), c(-1), vec2d(vec2d) {
        // Initialize your data structure here

        num_r = vec2d.size();
        num_c = (num_r > 0) ? vec2d[0].size() : 0;
    }

    int next() {
        // Write your code here

        return vec2d[r][c];
    }

    bool hasNext() {
        // Write your code here

        while (r < num_r) {
            ++c;

            if (c < num_c) {
                return true;
            }

            c = -1;
            ++r;
            if (r == num_r) {
                break;
            }

            num_c = vec2d[r].size();
        }

        return false;
    }

private:
    int r, c, num_r, num_c;
    std::vector<std::vector<int>> vec2d;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
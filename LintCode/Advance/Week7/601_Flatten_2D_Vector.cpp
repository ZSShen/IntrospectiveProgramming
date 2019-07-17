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


class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d)
        : total_row(vec2d.size()), index_row(0), total_col(0), index_col(0),
          vec2d(vec2d) {
        // Initialize your data structure here

        if (index_row < total_row) {
            total_col = vec2d[0].size();
        }
    }

    int next() {
        // Write your code here

        return cache;
    }

    bool hasNext() {
        // Write your code here

        // Adjust the iterators first and please be careful about empty vectors.
        while (index_col == total_col) {
            if (index_col == 0 && index_row == total_row) {
                return false;
            }

            ++index_row;
            index_col = 0;
            total_col = (index_row < total_row) ? vec2d[index_row].size() : 0;
        }

        cache = vec2d[index_row][index_col];
        ++index_col;

        return true;
    }

private:
    int total_row;
    int index_row;

    int total_col;
    int index_col;

    std::vector<std::vector<int>> vec2d;

    int cache;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

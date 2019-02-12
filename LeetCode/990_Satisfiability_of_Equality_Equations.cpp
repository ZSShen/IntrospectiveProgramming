class Set {
public:
    Set(int size)
        : sets_(size, -1)
    { }

    int find(int curr) {
        if (sets_[curr] == -1) {
            return curr;
        }
        sets_[curr] = find(sets_[curr]);
        return sets_[curr];
    }

    void unite(int src, int dst) {
        int rep_src = find(src);
        int rep_dst = find(dst);
        if (rep_src != rep_dst) {
            sets_[rep_src] = rep_dst;
        }
    }

private:
    std::vector<int> sets_;
};


class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        Set sets(26);

        for (const auto& equation : equations) {
            if (equation[1] == '=') {
                sets.unite(
                    static_cast<int>(equation[0] - 'a'),
                    static_cast<int>(equation[3] - 'a')
                );
            }
        }

        for (const auto& equation : equations) {
            if (equation[1] == '!') {
                int rep_src = sets.find(static_cast<int>(equation[0] - 'a'));                             int rep_dst = sets.find(static_cast<int>(equation[3] - 'a'));
                if (rep_src == rep_dst) {
                    return false;
                }
            }
        }

        return true;
    }
};
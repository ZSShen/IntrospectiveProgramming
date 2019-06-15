class DisjointSet {
public:
    DisjointSet(int n)
      : parents(std::vector<int>(n)) {
        for (int i = 0 ; i < n ; ++i) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] == x) {
            return x;
        }

        parents[x] = find(parents[x]);
        return parents[x];
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa != pb) {
            parents[pa] = pb;
        }
    }

private:
    std::vector<int> parents;
};


class Solution {
public:
    /**
     * @param accounts: List[List[str]]
     * @return: return a List[List[str]]
     */
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // write your code here

        /**
         *   JS  -> 0, 2,
         *   J00 -> 0,
         *   JB  -> 1,
         *   JN  -> 2
         *   Ma  -> 3
         *
         *   0  1  3
         *   ^
         *   |
         *   2
         *
         *   0 -> JS, Joo, JN
         *   1 -> JB
         *   4 -> Ma
         */

        auto mail_to_account = getEmailToAccountIdMap(accounts);

        DisjointSet set(accounts.size());
        for (const auto& pair : mail_to_account) {
            const auto& user_ids = pair.second;
            int size = user_ids.size();

            int src = user_ids[0];
            for (int i = 1 ; i < size ; ++i) {
                int dst = user_ids[i];
                set.unite(src, dst);
            }
        }

        auto account_to_mail = getAccountIdToEmailMap(accounts, set);

        std::vector<std::vector<std::string>> ans;
        for (const auto& pair : account_to_mail) {
            int rep_id = pair.first;
            const auto& emails = pair.second;

            std::vector<std::string> info;

            info.push_back(accounts[rep_id][0]);
            for (const auto& email : emails) {
                info.push_back(email);
            }

            std::sort(info.begin() + 1, info.end());
            ans.emplace_back(std::move(info));
        }

        return ans;
    }

private:
    std::unordered_map<std::string, std::vector<int>>
    getEmailToAccountIdMap(std::vector<std::vector<std::string>>& accounts) {

        std::unordered_map<std::string, std::vector<int>> map;

        int num = accounts.size();
        for (int user_id = 0 ; user_id < num ; ++user_id) {
            const auto& account = accounts[user_id];
            int len = account.size();

            for (int j = 1 ; j < len ; ++j) {
                const auto& email = account[j];
                map[email].push_back(user_id);
            }
        }

        return map;
    }

    std::unordered_map<int, std::unordered_set<std::string>>
    getAccountIdToEmailMap(
        std::vector<std::vector<std::string>>& accounts,
        DisjointSet& set) {

        std::unordered_map<int, std::unordered_set<std::string>> map;

        int num = accounts.size();
        for (int user_id = 0 ; user_id < num ; ++user_id) {
            const auto& account = accounts[user_id];
            int len = account.size();

            int rep_id = set.find(user_id);

            for (int j = 1 ; j < len ; ++j) {
                map[rep_id].insert(account[j]);
            }
        }

        return map;
    }

};
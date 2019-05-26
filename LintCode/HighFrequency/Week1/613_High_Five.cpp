/**
 * Definition for a Record
 * class Record {
 * public:
 *   int id, score;
 *   Record(int id, int score) {
 *     this->id = id;
 *     this->score = score;
 *   }
 * };
 */
class Solution {
public:
    /**
     * @param results a list of <student_id, score>
     * @return find the average of 5 highest scores for each person
     * map<int, double> (student_id, average_score)
     */
    map<int, double> highFive(vector<Record>& results) {
        // Write your code here

        std::unordered_map<
            int, std::priority_queue<int, std::vector<int>, greater<int>>> map;

        for (const auto& result : results) {
            int id = result.id;
            int score = result.score;

            map[id].push(score);
            if (map[id].size() > 5) {
                map[id].pop();
            }
        }

        std::map<int, double> ans;
        for (auto& pair : map) {
            int id = pair.first;

            double avg = 0;
            auto& queue = pair.second;
            int size = queue.size();

            while (!queue.empty()) {
                avg += queue.top();
                queue.pop();
            }

            avg /= size;
            ans[id] = avg;
        }

        return ans;
    }
};
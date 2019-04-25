x   /**
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
        
        std::unordered_map<int, 
            std::priority_queue<int, std::vector<int>, std::greater<int>>> profile;
        for (const auto& result : results) {
            profile[result.id].push(result.score);
            if (profile[result.id].size() > 5) {
                profile[result.id].pop();
            }
        }
        
        std::map<int, double> ans;
        for (auto& pair : profile) {
            int id = pair.first;
            auto& queue = pair.second;
            
            double sum = 0;
            while (!queue.empty()) {
                sum += queue.top();
                queue.pop();
            }
            
            ans[id] = sum / 5;
        }
        
        return ans;
    }
};
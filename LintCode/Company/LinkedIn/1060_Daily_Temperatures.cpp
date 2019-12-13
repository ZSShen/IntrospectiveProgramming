

struct Record {
    int temp;
    int index;

    Record(int temp, int index)
      : temp(temp), index(index)
    { }
};


class Solution {
public:
    /**
     * @param temperatures: a list of daily temperatures
     * @return: a list of how many days you would have to wait until a warmer temperature
     */
    vector<int> dailyTemperatures(vector<int> &temps) {
        // Write your code here

        int n = temps.size();

        std::vector<int> ans(n, 0);

        std::stack<Record> stack;
        stack.push(Record(temps[0], 0));

        for (int i = 1 ; i < n ; ++i) {
            if (temps[i] <= stack.top().temp) {
                stack.push(Record(temps[i], i));
            } else {
                while (!stack.empty() && temps[i] > stack.top().temp) {
                    int j = stack.top().index;
                    ans[j] = i - j;
                    stack.pop();
                }
                stack.push(Record(temps[i], i));
            }
        }

        return ans;
    }
};
#include <list>

class DataStream {
public:

    DataStream(){
        // do intialization if necessary
    }

    /**
     * @param num: next number in stream
     * @return: nothing
     */
    void add(int num) {
        // write your code here

        if (set_.count(num) == 1) {
            return;
        }

        if (map_.count(num) == 0) {
            list_.push_back(num);
            map_[num] = --list_.end();
        } else {
            auto& iter = map_[num];
            list_.erase(iter);
            map_.erase(num);
            set_.insert(num);
        }
    }

    /**
     * @return: the first unique number in stream
     */
    int firstUnique() {
        // write your code here

        if (list_.size() == 0) {
            return -1;
        }

        return list_.front();
    }

private:
    std::list<int> list_;
    std::unordered_map<int, std::list<int>::iterator> map_;
    std::unordered_set<int> set_;
};

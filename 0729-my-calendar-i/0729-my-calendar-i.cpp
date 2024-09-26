#include <map>

class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = calender.lower_bound(start);
        if (it != calender.end() && it->first < end) {
            return false;
        }
        if (it != calender.begin() && (--it)->second > start) {
            return false;
        }
        calender[start] = end;
        return true;
    }

private:
    std::map<int, int> calender; // Declaring the map here
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

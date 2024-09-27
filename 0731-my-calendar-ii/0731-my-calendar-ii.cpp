class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
		for (auto& p : books) {
			if (p.second > start && p.first < end) {
				return false;
			}
		}
		for (auto& p : overlaps) {
			if (p.second > start && p.first < end) {
				books.push_back({max(p.first, start), min(p.second, end)});
			}
		}
		overlaps.push_back({start, end});
		return true;
    }
private:
	vector<pair<int, int>> books, overlaps;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
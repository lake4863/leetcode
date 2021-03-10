class MyCalendarThree {
private:
    vector<vector<int>> intervals;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    MyCalendarThree() {
        intervals.clear();
    }
    
    int book(int start, int end) {
        intervals.push_back({ start, end });
        sort(intervals.begin(), intervals.end(), [](vector<int> lhs, vector<int> rhs) {
            return lhs[0] < rhs[0];
        });
        while(!pq.empty()) pq.pop();
        
        for(auto i : intervals) {
            if(!pq.empty() && i[0] >= pq.top()) {
                pq.pop();
            }
            pq.push(i[1]);
        }
        
        return pq.size();
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
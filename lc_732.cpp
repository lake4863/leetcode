class MyCalendarThree {
private:
    map<int, int> count;
    int con;
    int result;
public:
    MyCalendarThree() {
        con = 0;
        result = 0;
        count.clear();
    }
    
    int book(int start, int end) {
        ++count[start];
        --count[end];
        
        /*
        for(auto i : intervals) {
            if(count.find(i[0]) == count.end()) {
                count[i[0]] = 1;
            } else {
                ++count[i[0]];
            }
            
            if(count.find(i[1]) == count.end()) {
                count[i[1]] = -1;
            } else {
                --count[i[1]];
            }
        }
        */
        
        for(auto it = count.begin(); it != count.end(); ++it) {
            con += it->second;
            result = max(result, con);
        }
        
        return result;        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
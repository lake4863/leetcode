class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return 0;
        int result = 0;
        vector<int> pre;
        
        //sort(intervals.begin(), intervals.end());
        sort(intervals.begin(), intervals.end(), [](auto lhs, auto rhs) {
            return (lhs[0] == rhs[0]) ? lhs[1] > rhs[1] : lhs[0] < rhs[0];
        });
        
        /*
        sort(intervals.begin(), intervals.end(), [](auto lhs, auto rhs) {
            if(lhs[1] != rhs[1]) {
                return lhs[1] < rhs[1];
            } else {
                return lhs[0] > rhs[0];
            }
        });
        */
        
        //for(auto i : intervals) cout << i[0] << " : " << i[1] << endl;
        
        pre = intervals[0];
        for(int i = 1; i < intervals.size(); ++i) {
            //cout << intervals[i][0] << ", " << intervals[i][1] << endl;
            if(intervals[i][1] <= pre[1]) {
            //cout << intervals[i][0] << ",** " << intervals[i][1] << endl;
                ++result;
            } else if(intervals[i][1] >= pre[1]) {    // && intervals[i][1] >= pre[1]) {
                pre = intervals[i];
            }
        }
        
        return intervals.size() - result;
    }
};

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() < 2) return 0;
        int result = 0;
        vector<int> pre;
        
        sort(intervals.begin(), intervals.end(), [](auto lhs, auto rhs) {
            if(lhs[1] != rhs[1]) {
                return lhs[1] < rhs[1];
            } else {
                return lhs[0] > rhs[0];
            }
        });
        
        //for(auto i : intervals) cout << i[0] << " : " << i[1] << endl;
        
        pre = intervals[intervals.size() - 1];
        for(int i = intervals.size() - 2; i >= 0; --i) {
            //cout << intervals[i][0] << ", " << intervals[i][1] << endl;
            if(intervals[i][0] >= pre[0]) {
            //cout << intervals[i][0] << ",** " << intervals[i][1] << endl;
                ++result;
            } else if(intervals[i][0] <= pre[0]) {    // && intervals[i][1] >= pre[1]) {
                pre = intervals[i];
            }
        }
        
        return intervals.size() - result;
    }
};
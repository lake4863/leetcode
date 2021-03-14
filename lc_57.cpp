class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int sta = newInterval[0];
        int end = newInterval[1];
        
        if(intervals.size() == 0) result.push_back(newInterval);
        
        for(int i = 0; i < intervals.size(); ++i) {
            if(intervals[i][1] < newInterval[0]) {
                result.push_back(intervals[i]);
            } else if(intervals[i][1] >= newInterval[0] && (i - 1 < 0 || intervals[i - 1][1] < newInterval[0])) {
                sta = min(intervals[i][0], newInterval[0]);
                //cout << "sta = [" << intervals[i][0] << ", " << intervals[i][1] << "]" << sta << endl;
            } 
            
            if(intervals[i][0] > newInterval[1]) {
                result.push_back(intervals[i]);
                // end = -1;
            } else if(i - 1 < 0 || intervals[i - 1][0] < newInterval[1]) {
                end = max(intervals[i][1], newInterval[1]);
                //cout << "end = [" << intervals[i][0] << ", " << intervals[i][1] << "]" << end << endl;
                if(sta != -1 && (i + 1 > intervals.size() - 1 || end < intervals[i + 1][0])) {
                    result.push_back({ sta, end });
                }
            }
        }
        
        if(result.size() == 0 || 
           (intervals.size() > 0 && newInterval[1] < intervals[0][0]) || 
           (sta == -1 && result[result.size() - 1][0] != newInterval[0])) result.push_back(newInterval);
        
        sort(result.begin(), result.end(), [](auto lhs, auto rhs) { return lhs[0] < rhs[0]; });
        
        return result;
    }
};
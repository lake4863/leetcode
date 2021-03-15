class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> result;
        int start = -1;
        int end = -1;
        int index = 0;
        
        while(index < intervals.size() && intervals[index][0] < toBeRemoved[0]) {
            end = min(intervals[index][1], toBeRemoved[0]);
            result.push_back({ intervals[index][0], end });
            ++index;
        }
        
        index = 0;
        while(index < intervals.size() && intervals[index][1] <= toBeRemoved[1]) {
            ++index;
        }
        
        while(index < intervals.size() && intervals[index][1] > toBeRemoved[1]) {
            start = max(intervals[index][0], toBeRemoved[1]);
            result.push_back({ start, intervals[index][1] });
            ++index;
        }
        
        return result;
    }
};
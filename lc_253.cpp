class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& lhs, vector<int>& rhs) {
            return lhs[0] < rhs[0];
        });
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i : intervals) {
            if(!pq.empty() && pq.top() <= i[0]) {
                pq.pop();
            }
            pq.push(i[1]);
        }
        return pq.size();
    }
};

// code below do not work, need dealing with equal intervals
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int result = 1;
        int mx = 1;
        int minEnd = intervals[0][1];
        int maxBegin = intervals[0][0];
        sort(intervals.begin(), intervals.end());
        
        for(int i = 1; i < intervals.size(); ++i) {
            minEnd = min(minEnd, intervals[i][1]);
            maxBegin = max(maxBegin, intervals[i][0]);
            
            //++mx;
            
            cout << maxBegin << ", " << minEnd << ", mx = " << mx << endl;
            if(intervals[i - 1][1] <= maxBegin) {
                --mx;
            } else {
                mx = 1;
            }
            
            cout << maxBegin << ", " << minEnd << ", mx = " << mx << endl;
            cout << "i = " << i << "intervals = " << intervals[i][0] << ", " << intervals[i][1] << endl;
            
            if(intervals[i][0] < minEnd) {
                ++mx;
                result = max(result, mx);
            } else {
                minEnd = intervals[i][1];
            }
        }
               
        return result;
    }
};
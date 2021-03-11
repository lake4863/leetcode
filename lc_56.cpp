// this time's method 20210311


// last time's solution 20210224
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
            return (lhs[0] < rhs[0]);
        });
        
        for(auto it = intervals.begin() + 1; it != intervals.end(); ++it) {
            if((*it)[0] <= (*(it - 1))[1]) {
                (*it)[0] = (*(it - 1))[0];
                if((*it)[1] > (*(it - 1))[1]) {
                    (*(it - 1))[0] = -1;
                } else {
                    (*it)[1] = (*(it - 1))[1];
                    (*(it - 1))[0] = -1;
                }
            }
        }
        
        for(auto i : intervals) {
            if(i[0] != -1) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
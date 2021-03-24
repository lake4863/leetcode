class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;
        
        for(int i = 1; (i < arr.size()) && (arr[i] >= arr[i - 1]); ++i) {
            start = i;
        }
        
        for(int i = arr.size() - 1; (i > 0) && (arr[i] >= arr[i - 1]); --i) {
            end = i - 1;
        }
        
        //cout << start << ", " << end << endl;
        
        if(start >= end) {
            return 0;
        }
        
        int minn = min((size_t)end, arr.size() - 1 - start);
        int i = 0;
        while(i <= start && end < arr.size()) {
            if(arr[end] >= arr[i]) {
                minn = min(end - i - 1, minn);
                ++i;
            } else {
                ++end;
            }
        }
        
        return minn;
    }
};
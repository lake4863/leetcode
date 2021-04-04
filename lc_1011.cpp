class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int n = weights.size();
        int lo = *max_element(weights.begin(), weights.end());
        int hi = 25e6;
        
        while(lo < hi) {
            int time = 1;
            int mi = lo + (hi - lo) / 2;
            int cur = 0;
            
            for(int i = 0; i < n; cur += weights[i], ++i) {
                if(cur + weights[i] > mi) {
                    cur = 0;
                    ++time;
                }
                //cout << "time = " << time << endl;
            } 
            
            //cout << "time = " << time << ", mi = " << mi << ", lo = " << lo << ", hi = " << hi << endl;
            if(time > D) {
                lo = mi + 1;
            } else {
                hi = mi;
            }
        }
        
        return lo;
    }
};
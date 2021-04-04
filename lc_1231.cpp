class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int lo = 1;
        int hi = 1e9;
        
        while(lo < hi) {
            int mi = lo + (1 + hi - lo) / 2;
            int cur = 0;
            int cuts = 0;
            for (int a : sweetness) {
                if ((cur += a) >= mi) {
                    cur = 0;
                    if (++cuts > K) break;
                }
            }
            
            if(cuts > K) {
                lo = mi;
            } else {
                hi = mi - 1;
            }
        }
        
        return lo;
    }
};
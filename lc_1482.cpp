class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int lo = 1;
        int hi = 1e9;
        int mid;
        
        if(m * k > n) return -1;
        
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            //cout << mid << ", " << lo << ", " << hi << endl;
            if(ccont(bloomDay, mid, k) < m) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        return lo;
    }
    
    int ccont(vector<int>& A, int mid, int k) {
        int bouq = 0;
        int n = A.size();
        int flow = 0;
        
        for (int j = 0; j < n; ++j) {
            if (A[j] > mid) {
                flow = 0;
            } else if (++flow >= k) {
                bouq++;
                flow = 0;
            }
        }
        
        return bouq;
    }
};
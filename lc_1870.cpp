class Solution {
private:
    bool inTime(vector<int>& dist, double hour, int speed) {
        int n = dist.size();
        double h = 0;
        
        for(int i = 0; i < n - 1; ++i) {
            h += (dist[i] + speed - 1) / speed;
        }
        h += dist[n - 1] / (double)speed;
        
        return h <= hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int lo = 1;
        int hi = 1e7;
        int mi = lo + (hi - lo) / 2;
        if(hour <= (double)(n - 1)) return -1;
        
        while(lo < hi) {
            mi = lo + (hi - lo) / 2; 
            //h = accumulate(begin(dist), end(dist), 0, [&](int i) { return (i + mi) / mi; });
            
            if(inTime(dist, hour, mi)) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        
        return hi;
    }
};
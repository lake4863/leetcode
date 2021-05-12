class Solution {
public:
    int hIndex(vector<int>& citations) {
        int lo = 0;
        int hi = citations.size() - 1;
        int mi = 0;
        
        while(lo <= hi) {
            mi = lo + (hi - lo) / 2;
            if(citations[mi] < citations.size() - mi) {
                lo = mi + 1;
            } else {
                hi = mi - 1;
            }
        }
        //cout << lo << ", " << mi << ", " << hi << endl;
        return citations.size() - lo;
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        for(int i = 0; i < citations.size(); ++i) {
            if(citations[i] >= citations.size() - i) {
                return citations.size() - i;
            }
        }
        return 0;
    }
};
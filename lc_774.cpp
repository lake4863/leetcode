class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double lo = 0;
        double hi = 1e9;
        int n = stations.size();
        vector<int> dis(n, 0);
        
        for(int i = 1; i < n; ++i) {
            dis[i - 1] = stations[i] - stations[i - 1];
            //cout << stations[i] - stations[i - 1] << ", ";
        }
        
        //hi = *max_element(begin(dis), end(dis));
        
        while(lo + 1e-6 < hi) {
            double mi = lo + (hi - lo) / 2;
            int cuts = 0;
            
            for(auto i : dis) {
                cuts += i / mi;
                //cout << cuts << ", ";
            }
            
            if(cuts <= k) {
                hi = mi;
            } else {
                lo = mi;
            }
        }
        
        return lo;
    }
};

// shangmian de jiejian le xiamian de 1e-6 and count part
double minmaxGasDist(vector<int>& st, int K) {
	int count, N = st.size();
	double left = 0, right = st[N - 1] - st[0], mid;
	while (left + 1e-6 < right) {
		mid = (left + right) / 2;
		count = 0;
		for (int i = 0; i < N - 1; ++i)
			count += ceil((st[i + 1] - st[i]) / mid) - 1;
		if (count > K) left = mid;
		else right = mid;
	}
	return right;
}
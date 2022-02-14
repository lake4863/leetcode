class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        int n = beans.size();
        int cur = beans[0];
        long long sum = 0;
        long long res = 0;
        
        for(int i = 0; i < n; ++i) {
            sum += beans[i];
            res = max(res, (long long)beans[i] * (n - i));
        }
        
        return sum - res;
    }
};

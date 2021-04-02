class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int hi = 1e9;
        int mid = 0;
        int sum = 0;
        
        if(threshold == nums.size()) return *max_element(nums.begin(), nums.end());
        
        while(lo < hi) {
            mid = lo + (hi - lo) / 2;
            sum = ccount(nums, mid);
        
            //cout << "1, sum = " << sum << ", mid = " << mid << endl;
            if(sum > threshold) {
                lo = mid + 1;
            //cout << "2, lo = " << lo << ", hi = " << hi << endl;
            } else {
                hi = mid;
            }
        }
        
        return lo;
    }
    
    int ccount(vector<int>& nums, int mid) {
        int sum = 0;
        
        for(int i : nums) sum += (i + mid - 1) / mid;
        
        return sum;
    }
};
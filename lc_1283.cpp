class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int hi = 1e9;
        int mid = 0;
        int sum = 0;
        
        //if(threshold == nums.size()) return *max_element(nums.begin(), nums.end());
        
        while(lo < hi) {
            sum = 0;
            mid = lo + (hi - lo) / 2;
        
            for(int i : nums) sum += (i + mid - 1) / mid;
            
            if(sum > threshold) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        return lo;
    }
};
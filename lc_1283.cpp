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

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(), left = 1, right = *max_element(nums.begin(), nums.end());
        while (left <= right) {
            int mid = left + (right-left)/2, sum = 0;
            for (auto num:nums) sum += (num%mid ? num/mid+1 : num/mid);
            sum <= threshold ? right = mid-1 : left = mid+1;
        }
        return left;
    }
};

/*
    binary search
    left = 1, right = max_element(nums)
    
    sum <= threshold right = mid-1
    else left = mid+1
    
*/
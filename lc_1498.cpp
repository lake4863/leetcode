class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int result = 0;
        int minn = *min_element(nums.begin(), nums.end());
        int len = nums.size();
        int mod = 1e9 + 7;
        int l = 0;
        int r = len - 1;
        
        sort(begin(nums), end(nums));
        
        vector<int> pow(len, 1);
        for(int i = 1; i < len; ++i) pow[i] = pow[i - 1] * 2 % mod;
        
        while(l <= r) {
            if(nums[l] <= target - nums[r]) {
                result = (result + pow[r - l]) % mod;
                ++l;
            } else {
                --r;
            }
        }
        
        return result;
    }
};
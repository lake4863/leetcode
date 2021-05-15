class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        vector<int> sub(n, 0);
        
        sort(nums.begin(), nums.end());
        
        for(int i = 1; i < n; ++i) {
            sub[i - 1] = nums[i] - nums[i - 1]; 
        }
        
        return *max_element(sub.begin(), sub.end());
    }
};
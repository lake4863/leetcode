class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(begin(nums), end(nums), 0);
        
        int n = nums.size();
        int cur = 0;
        int res = -1;
        int l = 0;
        
        for(int r = 0; r < n; ++r) {
            cur += nums[r];
            while(cur > sum - x && l <= r) {
                cur -= nums[l];
                ++l;
            }
            
            if(cur == sum - x) {
                //cout << "l = " << l << ", r = " << r << endl;
                res = max(res, r - l + 1);
            }
        }
        return res == -1 ? -1 : n - res;
    }
};
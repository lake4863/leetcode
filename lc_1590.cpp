class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int rem = 0;
        int cur = 0;
        int res = n;
        
        for(int i : nums) {
            rem = (rem + i) % p;
        }
        if(!rem) return 0;
        
        unordered_map<int, int> m({{0, -1}});
        
        for(int i = 0; i < n; ++i) {
            cur = (cur + nums[i]) % p;
            m[cur] = i;
            int want = (cur - rem + p) % p;
            if(m.count(want)) {
                res = min(res, i - m[want]);
            }
        }
        
        return res < n ? res : -1;
    }
};
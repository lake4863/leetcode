class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> m({{0, 1}});
        int res = 0;
        int sum = 0;
        
        for(int i : nums) {
            sum += i;
            res += m[sum - goal];
            ++m[sum];
        }
        
        return res;
    }
};
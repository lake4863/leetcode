class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // multiple submit proves that running time calculating is not accurate.
        int hi = nums.size();
        int total = hi * (hi + 1) / 2;
        
        for(int i : nums) {
           total -= i;
        }
        
        return total;
    }
};

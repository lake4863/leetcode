class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        
        for(; i > - 1 && nums[i + 1] <= nums[i]; ) {
            --i;
        }
        if(i > -1) {
            int j = nums.size() - 1;
            for(; nums[j] <= nums[i]; ) {
                --j;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

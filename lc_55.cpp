class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxx = nums[0];
        int n = nums.size();
        for(int i = 0; i < n && i <= maxx; ++i) {
            maxx = max(maxx, nums[i] + i);
        }
        if(maxx >= n - 1) return true;
        else return false;
    }
};
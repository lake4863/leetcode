class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int minn = nums[k];
        int i = k;    // left index of range
        int j = k;    // right index of range
        int result = minn;
        int len = nums.size() - 1;
        
        while(j < len || i > 0) {
            if((i <= 0 ? 0 : nums[i - 1]) > (j >= len ? 0 : nums[j + 1])) {
                --i;
                minn = min(minn, nums[i]);
            } else {
                ++j;
                minn = min(minn, nums[j]);
            }
            result = max(result, minn * (j - i + 1));
        }
        
        return result;
    }
};

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int minn = nums[k];
        int i = k;    // left index of range
        int j = k;    // right index of range
        int result = minn;
        int len = nums.size() - 1;
        
        while(j < len || i > 0) {
            int lhs;
            int rhs;
            if(i <= 0) {
                lhs = 0;
            } else {
                lhs = nums[i - 1];
            }
            if(j >= len) {
                rhs = 0;
            } else {
                rhs = nums[j + 1];
            }
            
            if(lhs > rhs) {
                --i;
                minn = min(minn, nums[i]);
            } else {
                ++j;
                minn = min(minn, nums[j]);
            }
            
            result = max(result, minn * (j - i + 1));
        }
        
        return result;
    }
};
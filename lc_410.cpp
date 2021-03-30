class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int len = nums.size();
        vector<vector<int>> dp(m + 1, vector<int>(len, INT_MAX));
        vector<int> subsum(len, 0);
        
        subsum[0] = nums[0];
        for(int i = 1; i < len; ++i) {
            subsum[i] = nums[i] + subsum[i - 1];
        }
        
        for(int i = 0; i < len; ++i) {
            dp[1][i] = subsum[i];
        }
        
        for(int i = 2; i <= m; ++i) {
            for(int j = i - 1; j < len; ++j) {
                for(int k = 0; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][k], subsum[j] - subsum[k]));
                }
            }
        }
        
        return dp[m][len - 1];
    }
};
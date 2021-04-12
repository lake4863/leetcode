class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;
        vector<vector<int>> Cnk(n + 1, vector<int>(n + 1, 1));
        
        for(int i = 2; i < n; ++i) {
            for(int j = 1; j < i; ++j) {
                Cnk[i][j] = (Cnk[i - 1][j - 1] + Cnk[i - 1][j]) % mod;
            }
        }
        
        return dfs(Cnk, nums, mod) - 1;
    }
    
    int dfs(vector<vector<int>>& Cnk, vector<int>& nums, int mod) {
        int n = nums.size();
        if(n <= 2) return 1;
        
        vector<int> left;
        vector<int> right;
        for(int i = 1; i < n; ++i) {
            if(nums[i] > nums[0]) right.push_back(nums[i]);
            else left.push_back(nums[i]);
        }
        long ans = Cnk[n - 1][left.size()];
        ans = (ans * dfs(Cnk, left, mod)) % mod;
        ans = (ans * dfs(Cnk, right, mod)) % mod;
        
        return static_cast<int>(ans);
    }
};
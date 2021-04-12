class Solution {
public:
    int numOfWays(vector<int>& nums) {
        return _trav(nums) -1;
    }
private:
    int _trav(vector<int>& nums) {
        if (nums.size() <= 1) return 1;
        static const int mod = 1e9 + 7;
        vector<int> l, r;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[0]) r.push_back(nums[i]);
            else if (nums[i] < nums[0]) l.push_back(nums[i]);
        }
        long ln = _trav(l);
        long rn = _trav(r);
        long ret = (ln * rn) % mod;
        ret = ret * _comb(l.size(), r.size());
        return ret % mod;
    }
    int _comb(int n1, int n2) {
        static vector<vector<int>> dp(1001, vector<int>(1001, 0));
        static const int mod = 1e9+7;
        if (n1 == 0 || n2 == 0) return 1;
        if (dp[n1][n2]) return dp[n1][n2];
        int n = ( _comb(n1-1, n2) + _comb(n2-1, n1)) % mod;
        dp[n1][n2] = n;
        return n;
    }
};

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
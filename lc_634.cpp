class Solution {
private:
    int find(int n, vector<int>& memo) {
        if(n == 0) return 1;
        if(n == 1) return 0;
        if(memo[n] != -1) {
            return memo[n];
        }
        memo[n] = (int)(((n - 1l) * (find(n - 1, memo) + find(n - 2, memo))) % 1000000007);
        
        return memo[n];
    }
public:
    int findDerangement(int n) {
        vector<int> memo(n + 1, -1);
        
        return find(n, memo);
    }
};

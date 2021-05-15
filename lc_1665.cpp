class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int sum = 0;
        
        sort(tasks.begin(), tasks.end(), [](auto& lhs, auto& rhs) {
            return lhs[1] - lhs[0] < rhs[1] - rhs[0];
        });
        
        for(auto v : tasks) {
            sum = max(sum + v[0], v[1]);
        }
        
        return sum;
    }
};
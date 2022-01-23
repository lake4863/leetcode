class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int minn = n;
        int maxx = -1;
        
        for(int j = 0; j < n; ++j) {
            unordered_set<int> nums;
            for(int i : matrix[j]) {
                nums.insert(i);
                minn = min(minn, i);
                maxx = max(maxx, i);
            }
            if(nums.size() != n || minn != 1 || maxx != n) {
                return false;
            }
        }
        
        for(int j = 0; j < n; ++j) {
            unordered_set<int> nums;
            for(int i = 0; i < n; ++i) {
                nums.insert(matrix[i][j]);
                minn = min(minn, matrix[i][j]);
                maxx = max(maxx, matrix[i][j]);
            }
            if(nums.size() != n || minn != 1 || maxx != n) {
                return false;
            }
        }
        
        return true;
    }
};

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int minn = distance(min_element(begin(nums), end(nums)), nums.end()) - 1;
        int maxx = distance(nums.begin(), max_element(begin(nums), end(nums)));
        int res = max(minn, maxx);
        //cout << minn << ", " << maxx << endl;
        
        for(int i = 0; i < n - res; ++i) {
            for(int j = n - 1; j > res; --j) {
                res = (nums[i] <= nums[j]) ? max(res, j - i) : res;
            }
        }
        
        return res;
    }
};

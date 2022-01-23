class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        if(nums.size() == 1) return nums;
        sort(nums.begin(), nums.end());
        int pre = nums[0];
        /*
        for(int i : nums) cout << i << " ";
        cout << endl;
        */
        vector<int> res;
        
        int i = 1;
        if(nums[i - 1] < nums[i] - 1) res.push_back(nums[i - 1]);
        for(; i < nums.size() - 1; ++i) {
            int n = nums[i];
            if(n > pre + 1 && (n < nums[i + 1] - 1)) {
                res.push_back(n);
            }
            pre = n;
        }
        if(nums[i - 1] < nums[i] - 1) res.push_back(nums[i]);
        return res;
    }
};

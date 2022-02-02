class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        /*
        int n = nums.size();
        if(n < 3) return res;
        
        unordered_map<int, int> cnt;
        unordered_set<int> sd;        //repeated num in nums
        unordered_set<int> ss(nums.begin(), nums.end());  //unique values in nums
        vector<int> v(ss.begin(), ss.end());  //unique values in nums
        
        for(int i = 0; i < n; ++i) {
            ++cnt[nums[i]];
        }
        
        if(cnt[0] > 2) {
            res.push_back({0, 0, 0});
        }
        
        for(int i = 0; i < n; ++i) {
            if(cnt[nums[i]] > 1 && nums[i] != 0) {
                sd.insert(nums[i]);
            }
        }
        
        vector<int> vd(sd.begin(), sd.end());
        for(int i = 0; i < vd.size(); ++i) {
            if(ss.find(-vd[i] * 2) != ss.end()) {
                res.push_back({vd[i], vd[i], -vd[i] * 2});
            }
        }
        */
        
        for(int i = 0; i < nums.size() && nums[i] <= 0; ++i) {
            unordered_set<int> s;
            if(i == 0 || nums[i - 1] != nums[i]) {
                for(int j = i + 1; j < nums.size(); ++j) {
                    int val = - nums[i] - nums[j];
                    if(s.find(val) != s.end()) {
                        res.push_back({nums[i], nums[j], val});
                        while(j + 1 < nums.size() && nums[j] == nums[j + 1]) {
                            ++j;
                        }
                    }
                    s.insert(nums[j]);
                }
            }
        }
        return res;
    }
};

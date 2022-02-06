class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd;
        vector<int> even;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(i % 2) {
                odd.push_back(nums[i]);
            } else {
                even.push_back(nums[i]);
            }
        }
        sort(odd.begin(), odd.end(), [](auto lhs, auto rhs){ return lhs > rhs; });
        sort(even.begin(), even.end());
        
        for(int i = 0; i < nums.size(); ++i) {
            if(i % 2) {
                nums[i] = odd[i / 2];
            } else {
                nums[i] = even[i / 2];
            }
        }
        return nums;
    }
};

class Solution {
private:
    array<int, 4> op2(vector<int>& nums, int start) {
        int first = 0;
        int second = 0;
        int cnt[100001] = {0};
        
        for(int i = start; i < nums.size(); i += 2) {
            ++cnt[nums[i]];
            if(cnt[nums[i]] >= cnt[first]) {
                if(nums[i] != first) {
                    second = first;
                }
                first = nums[i];
            } else if(cnt[nums[i]] > cnt[second]) {
                second = nums[i];
            }
        }
        return {cnt[first], first, cnt[second], second};
    }
public:
    int minimumOperations(vector<int>& nums) {
        auto odd = op2(nums, 1);
        auto even = op2(nums, 0);
        
        return nums.size() - (odd[1] != even[1] ? odd[0] + even[0] : max(odd[0] + even[2], odd[2] + even[0]));
    }
};

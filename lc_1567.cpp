class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        priority_queue<int> maxs;
        int start = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0) {
                maxs.push(nozero(nums, start, i - 1));
                start = i + 1;
            }
        }
        maxs.push(nozero(nums, start, nums.size() - 1));
        
        return maxs.top();
    }
    
    int nozero(vector<int> nums, int l, int r) {
        int count = 0;
        int maxx = -1;
        int minn = -1;
        
        for(int i = l; i <= r; ++i) {
            if(nums[i] < 0) {
                minn = i;
                break;
            }
        }
        for(int i = r; i >= l; --i) {
            if(nums[i] < 0) {
                maxx = i;
                break;
            }
        }
        
        for(int i = l; i <= r; ++i) {
            if(nums[i] < 0) {
                ++count;
            }
        }
            
        if(count % 2) {
            return max(r - minn, maxx - l);
        }
        
        return r - l + 1;
    }
};
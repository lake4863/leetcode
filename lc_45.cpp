class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        int start = 0;
        int end = 0;
        int step = 0;
        
        while(start <= end) {
            // each round of the loop is a range of a jump can reach
            int new_start = end + 1;
            for(int i = 0; i < new_start; ++i) {
                end = max(i + nums[i], end);
                if(end >= n - 1) {
                    return step + 1;
                }
            }
            start = new_start;
            ++step;
        }
        
        return -1;
    }
};
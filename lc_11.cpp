class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int res = 0;
        
        for(; l < r; ) {
            res = max(res, min(height[l], height[r]) * (r - l));
            
            if(height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return res;
    }
};

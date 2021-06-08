class Solution {
public:
    int specialArray(vector<int>& nums) {
        int count [102] = { 0 };
        int n = nums.size();
        
        for(int i : nums) {
            ++count[min(n, i)];
        }
        
        for(int i = n; i >= 0; --i) {
            count[i] = count[i + 1] + count[i];
            if(count[i] == i) {
                return i;
            }
        }
        return -1;
    }
};
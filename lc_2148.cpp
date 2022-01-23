class Solution {
public:
    int countElements(vector<int>& nums) {
        int maxx = -100001;
        int minn = 100001;
        int res = 0;
        unordered_map<int, int> m;
        
        for(int i : nums) {
            minn = min(minn, i);
            maxx = max(maxx, i);
            ++m[i];
        }
        
        for(auto it : m) {
            if(it.first != minn && it.first != maxx) {
                res += it.second;
            }
        }
        return res;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for(int i : nums) {
            if(!m.count(i)) {
                m[i] = 1;
            } else {
                m[i]++;
            }
        }
        
        return find_if(m.begin(), m.end(), [](auto it) {
            return it.second == 1;
        })->first;
    }
};

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> p;
        queue<int> n;
        vector<int> res;
        int c = nums.size() / 2;
        
        for(int i : nums) {
            if(i > 0) {
                p.push(i);
            } else {
                n.push(i);
            }
        }
        
        for(int i = 0; i < c; ++i) {
            res.push_back(p.front());
            res.push_back(n.front());
            p.pop();
            n.pop();
        }
        
        return res;
    }
};

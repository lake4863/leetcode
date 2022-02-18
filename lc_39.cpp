class Solution {
private:
    void combin(vector<int>& can, vector<int>& cbns, int tar, int s, vector<vector<int>>& res) {
        if(!tar) {
            res.push_back(cbns);
            return;
        } 
        
        for(int i = s; i < can.size(); ++i) {
            if(can[i] > tar) break;
            cbns.push_back(can[i]);
            combin(can, cbns, tar - can[i], i, res);
            cbns.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cbns;
        sort(candidates.begin(), candidates.end());
        
        combin(candidates, cbns, target, 0, res);
        
        return res;
        
        /*
        
        for(int i = n - 1; i > -1; --i) {
            int big = target / candidates[i];
            
            for(int j = 1; j < big + 1; ++j) {
                vector<int> sums = (n, candidates[i]);
                
                for(int k = 0; k < n; ++k) {
                    if((target - candidates[i] * j) % candidates[k] == 0) {
                        while()
                    }
                }
            }
        }
        */
    }
};

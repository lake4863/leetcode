class Solution {
private:
    void dfs(vector<int>& can, int tar, int s, vector<int>& cur, vector<vector<int>>& res) {
        if(!tar) {
            //sort(cur.begin(), cur.end());
            res.push_back(cur);
            return;
        }
        
        for(int i = s; i < can.size(); ++i) {
            int num = can[i];
            if(num > tar) return;
            if(i > s && num == can[i - 1]) continue;
            cur.push_back(num);
            dfs(can, tar - num, i + 1, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        
        dfs(candidates, target, 0, cur, res);
        
        return res;
    }
};

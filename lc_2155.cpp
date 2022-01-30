class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        int one = count(nums.cbegin(), nums.cend(), 1);
        vector<int> ones(n + 1);
        vector<int> zeros(n + 1);
        vector<int> scores(n + 1);
        //int zeros = count(nums.cbegin(), nums.cend(), 0);
        vector<int> res;
        int maxx = 0;
        
        if(nums[0] == 0) {
            zeros[0] = 1;
        } else {
            zeros[0] = 0;
        }
        
        if(nums[n - 1] == 1) {
            ones[n - 1] = 1;
        } else {
            ones[n - 1] = 0;
        }
        for(int i = 1; i < n; ++i) {
            if(nums[i] == 0) {
                zeros[i] = zeros[i - 1] + 1; 
            } else {
                zeros[i] = zeros[i - 1];
            }
        }
        for(int i = n - 2; i > -1; --i) {
            if(nums[i] == 1) {
                ones[i] = ones[i + 1] + 1;
            } else {
                ones[i] = ones[i + 1];
            }
        }
        zeros.insert(zeros.begin(), 0);
        ones.push_back(0);
        
        for(int i = 0; i < n + 1; ++i) {
            scores[i] = ones[i] + zeros[i];
            //cout << zeros[i] << " " << ones[i] << endl;
            maxx = max(maxx, scores[i]);
        }
        
        for(int i = 0; i < n + 1; ++i) {
            if(scores[i] == maxx) {
                res.push_back(i);
            }
        }
        return res;
    }
};

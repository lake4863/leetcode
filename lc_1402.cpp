class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<int> sums(n, 0);
        sort(begin(satisfaction), end(satisfaction));
        
        //for(auto i : satisfaction) cout << i << " ";
        for(int i = n - 1; i > -1; --i) {
            int sum = 0;
            for(int j = 0; j < i + 1; ++j) {
                //cout << " s = "<< n - i - 1 + j << "\tj = "<< j + 1;
                //cout << " s = "<< satisfaction[n - i - 1] << "\tj = "<< j + 1;
                sum += satisfaction[n - i - 1 + j] * (j + 1);
            }
            sums[n - i - 1] = sum;
        }
        
        int result = *max_element(sums.begin(), sums.end());
        return result > 0 ? result : 0;
    }
};
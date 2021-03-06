class NumArray {
private:
    vector<int> num;
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        num = nums;
        /*
        for(auto i : num) cout << i << ", ";
        cout << endl;
        */
        sum.resize(nums.size() + 1);
        sum[0] = 0;
        sum[1] = num[0];
        for(int i = 1; i < num.size(); ++i) {
            sum[i + 1] = sum[i] + num[i];
        }
    }
    
    int sumRange(int left, int right) {
        //cout << sum[right] << ", " << sum[left] << endl;
        return sum[right + 1] - sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        l_ = vector<int>(n, 0);
        c_ = vector<int>(n, 0);

        int max_len = 0;
        for(int i = 0; i < n; ++i) {
            max_len = max(max_len, len(nums, i));
        }

        int res = 0;
        for(int i = 0; i < n; ++i) {
            if(count(nums, i) == max_len) {
                res += count(nums, i);
            }
        }

        return res;
    }
private:
    vector<int> l_;
    vector<int> c_;

    int len(vector<int>& nums, int n) {
        if(n == 0) return 1;
        if(l_[n] > 0) return l_[n];

        int max_len = 1;

        for(int i = 0; i < n; ++i) {
            if(nums[n] > nums[i]) {
                max_len = max(max_len, len(nums, i) + 1);
            }
        }

        l_[n] = max_len;
        return l_[n];
    }

    int count(vector<int>& nums, int n) {
        if(n == 0) return 1;
        if(c_[n] > 0) return c_[n];
        
        int total_count = 0;
        int l = len(nums, n);
        for(int i = 0; i < n; ++i) {
            if(nums[n] > nums[i] && len(nums, i) == l - 1) {
                total_count += count(nums, i);
            }
        }

        if(total_count == 0) {
            total_count = 1;
        }
        
        c_[n] = total_count;
        return c_[n];
    }
};

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        vector<int> len(n, 1);
        vector<int> count(n, 1);
        
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j]) {
                    if(len[i] < len[j] + 1) {
                        len[i] = len[j] + 1;
                        count[i] = count[j];
                    } else if(len[i] == len[j] + 1) {
                        count[i] += count[j];
                    }
                }
            }
        }
        
        int max_len = *max_element(len.begin(), len.end());
        
        int res = 0;
        for(int i = 0; i < n; ++i) {
            if(len[i] == max_len) {
                res += count[i];
            }
        }
        
        return res;
    }
};

class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        if(n == 0) return 0;

        /*
        ArrayList<Integer> len = new ArrayList<Integer>(n);
        ArrayList<Integer> count = new ArrayList<Integer>(n);
        */
        int[] len = new int[n];
        int[] count = new int[n];

        int max_len = 0;
        for(int i = 0; i < n; ++i) {
            len[i] = count[i] = 1;
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j]) {
                    if(len[i] < len[j] + 1) {
                        len[i] = len[j] + 1;
                        count[i] = count[j];
                    } else if(len[i] == len[j] + 1) {
                        count[i] += count[j];
                    }
                }
            }
            max_len = Math.max(max_len, len[i]);
        }

        int res = 0;
        for(int i = 0; i < n; ++i) {
            if(len[i] == max_len) {
                res += count[i];
            }
        }
        return res;
    }
}

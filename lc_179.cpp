class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (all_of(nums.begin(), nums.end(), [](int i){ return i == 0; })) {
            return "0";
        }
        string result;
        
        sort(nums.begin(), nums.end(), [](int lhs, int rhs) {
            return to_string(lhs) + to_string(rhs) > to_string(rhs) + to_string(lhs);
        });
        
        for(int i : nums) {
            result += to_string(i);
        }
        
        return result; 
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (std::all_of(nums.cbegin(), nums.cend(), [](int i){ return i == 0; })) {
            return "0";
        }
        int n = nums.size();
        vector<string> vs(n);
        for(int i = 0; i < n; ++i) {
            vs[i] = to_string(nums[i]);
        }
        
        sort(vs.begin(), vs.end(), [](string lhs, string rhs) {
            return lhs + rhs < rhs + lhs;
        });
        //for(auto i : vs) cout << i << " ";
        string result;
        
        for(int i = n - 1; i > -1; --i) {
            result += vs[i];
        }
        
        return result; 
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> vs(n);
        for(int i = 0; i < n; ++i) {
            vs[i] = to_string(nums[i]);
        }
        
        sort(vs.begin(), vs.end(), [](string lhs, string rhs) {
            int l = lhs.length();
            int r = rhs.length();
            
            if(l == r) {
                return lhs < rhs;
            } else {
                int len = min(l, r);
                for(int i = 0; i < len; ++i) {
                    if(lhs[i] > rhs[i]) {
                        //cout << "hi hi" << endl;
                        return lhs < rhs;
                    } else {
                        //cout << "hi" << endl;
                        return rhs < lhs;
                    }
                }
                return (l > r) ? ((lhs[len] >= lhs[0]) ? lhs > rhs : rhs > lhs) : ((rhs[len] >= rhs[0]) ? lhs < rhs : rhs < lhs);
            }
        });
        //for(auto i : vs) cout << i << " ";
        string result;
        
        for(int i = n - 1; i > -1; --i) {
            result += vs[i];
        }
        
        return result; 
    }
};
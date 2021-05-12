class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        vector<int> copied(nums.begin(), nums.end());
        sort(begin(copied), end(copied));
        
        int start = 0;
        int end = n - 1;
        
        while(start <= end && ((nums[start] == copied[start]) || (nums[end] == copied[end]))) {
            if(nums[start] == copied[start]) {
                ++start;
            }
            
            if(nums[end] == copied[end]) {
                --end;
            }
        }
        //cout << start << ", " << end << endl;
        
        if(end <= start) {
            return 0;
        } else {
            return end - start + 1;
        }
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        vector<int> copied(nums.begin(), nums.end());
        sort(begin(copied), end(copied));
        
        int start = 0;
        int end = n - 1;
        
        while(start < n && nums[start] == copied[start]) {
            ++start;
        }

        while(end > -1 && nums[end] == copied[end]) {
            --end;
        }
        
        if(end <= start) {
            return 0;
        } else {
            return end - start + 1;
        }
    }
};
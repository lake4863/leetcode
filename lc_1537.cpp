class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int i1 = 0;      // index of nums1
        int i2 = 0;      // index of nums2
        long s1 = 0;     // partial sum of nums1
        long s2 = 0;     // partial sum of nums2
        int l1 = nums1.size();
        int l2 = nums2.size();
        int mod = 1e9 + 7;
        
        while(i1 < l1 || i2 < l2) {
            if(i1 < l1 && (i2 == l2 || nums1[i1] < nums2[i2])) {
                s1 += nums1[i1++];
            } else if(i2 < l2 && (i1 == l1 || nums2[i2] < nums1[i1])) {
                s2 += nums2[i2++];
            } else {
                s1 = s2 = max(s1, s2) + nums1[i1];
                ++i1;
                ++i2;
            }
        }
        
        return (int)(max(s1, s2) % mod);
    }
};
class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long, int> t1;
        unordered_map<long, int> t2;
        int count = 0;
        
        for(int i = 0; i < nums1.size() - 1; ++i) {
            for(int j = i + 1; j < nums1.size(); ++j) {
                ++t1[(long)nums1[i] * nums1[j]];
            }
        }
        
        for(int i = 0; i < nums2.size() - 1; ++i) {
            for(int j = i + 1; j < nums2.size(); ++j) {
                ++t2[(long)nums2[i] * nums2[j]];
            }
        }
        
        for(int i : nums1) {
            count += t2[(long)i * i];
        }
        //cout << "count = " << count << ", t1.size = " << t1.size() << ", t2.size = " << t2.size() << endl;
        for(int i : nums2) {
            count += t1[(long)i * i];
        }
        
        return count;
    }
};
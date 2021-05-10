class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n  = arr.size(), res = 1;
        vector<int> higher(n);
        vector<int> lower(n);
        higher[n - 1] = lower[n - 1] = 1;
        map<int, int> map;
        map[arr[n - 1]] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            auto hi = map.lower_bound(arr[i]), lo = map.upper_bound(arr[i]);
            if (hi != map.end()) higher[i] = lower[hi->second];
            if (lo != map.begin()) lower[i] = higher[(--lo)->second];
            if (higher[i]) res++;
            map[arr[i]] = i;
        }
        return res;
    }
};
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<vector<char>> v(numRows);
        int l = s.length();
        int step = 1;
        string res;
        int start = 0;
        
        v[start].push_back(s[0]);
        for(int i = 1; i < l; ++i) {
            start += step;
            v[start].push_back(s[i]);
            
            if(i % (numRows - 1) == 0) {
                step = -step;
            }
        }
        
        for(auto vec : v) {
            for(auto c : vec) {
                res += c;
            }
        }
        return res;
    }
};

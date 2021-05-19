class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0;
        int cmax = 0;
        
        for(char c : s) {
            if(c == '(') {
                ++cmin;
                ++cmax;
            } else if(c == '*') {
                cmin = max(cmin - 1, 0);
                ++cmax;
            } else {
                cmin = max(cmin - 1, 0);
                --cmax;
            }
            
            if(cmax < 0) {    // means ) too much unbalanced
                return false;
            }
        }
        
        return cmin == 0;    // unbalanced ( left over
    }
};
class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        int right = 0;
        
        for(char c : s) {
            if(c == '(') {
                right += 2;
                if(right % 2) {
                    ++res;
                    --right;
                }
            } else {
                --right;
                if(right < 0) {
                    ++res;
                    right += 2;
                }
            }
        }
        
        return res + right;
    }
};
class Solution {
public:
    int myAtoi(string s) {
        bool positive = true;
        bool readDigits = false;
        int res = 0;
        
        for(char c : s) {
            if(c == '-' || c == '+') {
                if(readDigits) {
                    return (positive) ? res : -res;
                } else if(c == '-') {
                    positive = false;
                }
                readDigits = true;
            } else if(isdigit(c)) {
                readDigits = true;
                if(res < INT_MAX / 10 || (res == INT_MAX / 10 && (c - '0') < 8)) {
                    res = res * 10 + (c - '0');
                } else {
                    return (positive) ? INT_MAX : INT_MIN;
                }
            } else if(c == ' ' && !readDigits) {
                
            } else {
                return (positive) ? res : -res;
            }
        }
        
        return (positive) ? res : -res;
    }
};

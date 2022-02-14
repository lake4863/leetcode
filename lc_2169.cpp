class Solution {
public:
    int countOperations(int num1, int num2) {
        int res = 0;
        if(!num1 || !num2) return 0;
        
        while(num1 || num2) {
            if(num1 > num2) {
                num1 = num1 - num2;
                ++res;
            } else if(num2 > num1) {
                num2 = num2 - num1;
                ++res;
            } else {
                return res + 1;
            }
        }
        
        return -1;
    }
};

class Solution {
public:
    int getSum(int a, int b) {
        int sign = (a > 0) ? 1 : -1;
        int x = abs(a);
        int y = abs(b);
        if(x < y) return getSum(b, a);
        
        if (a * b >= 0) {
            while(y != 0) {
                int res = x ^ y;
                int crr = (x & y) << 1;
                x = res;
                y = crr;
            } 
        } else {
            while(y != 0) {
                int res = x ^ y;
                int brr = ((~x) & y) << 1;
                x = res;
                y = brr;
            } 
        }
        return x * sign;
    }
};

class Solution {
private:    
    long long smallPositive(long long num) {
        vector<int> count(10);
        long long res = 0;
        
        while(num) {
            ++count[num % 10];
            num /= 10;
        }
        
        res = count[1] ? 1 : (count[2] ? 2 : (count[3] ? 3 : (count[4] ? 4 : (count[5] ? 5 : (count[6] ? 6 : (count[7] ? 7: (count[8] ? 8 : 9)))))));
        --count[res];
        for(int i = 0; i < 10; ++i) {
            while(count[i]) {
                res = res * 10 + i;
                --count[i];
            }
        }
        return res;
    }
    long long bigNegtive(long long num) {
        vector<int> count(10);
        long long res = 0;
        
        num = -num;
        while(num) {
            ++count[num % 10];
            num /= 10;
        }
        
        for(int i = 9; i > -1; --i) {
            while(count[i]) {
                res = res * 10 + i;
                --count[i];
            }
        }
        return -res;
    }
public:
    long long smallestNumber(long long num) {
        if(!num) return num;
        if(num > 0) {
            return smallPositive(num);
        } else {
            return bigNegtive(num);
        }
    }
};

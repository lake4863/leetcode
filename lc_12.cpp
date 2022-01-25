class Solution {
public:
    string intToRoman(int num) {
        string res;
        /*
        1  I
        2  IV
        3  V
        4  IX
        5  X
        6  XL
        7  L
        9  XC
        9  C
        10  CD
        11 D
        12 CM
        13 M
        */
        vector<int> n = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> r = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> count(13, 0);
        
        for(int i = 0; i < 13; ++i) {
            count[i] = num / n[i];
            num -= count[i] * n[i];
            //cout << count[i] << " ";
        }
        //cout << endl;
        
        for(int i = 0; i < 13; ++i) {
            for(int j = 0; j < count[i]; ++j) {
                res += r[i];
            }
        }
        return res;
        /*
        count[0] = num % 1000;
        num -= count[0] * 1000;
        count[1] = num % 900;
        num -= count[1] * 900;
        count[2] = num % 500;
        num -= count[2] * 500;
        count[3] = num % 100;
        num -= count[3] * 100;
        
        while(num) {
            while(num >= 900) {
                cout << "hahaha " << res << endl;
                res += 'M';
                num -= 1000;
            }

            while(num >= 400) {
                res += 'D';
                num -= 500;
            }

            while(abs(num) >= 90) {
                if(num > 0) {
                    res += 'C';
                    num -= 100;
                } else {
                    res = 'C' + res;
                    num += 100;
                }
            }
            
            while(num >= 50) {
                res += 'L';
                num -= 50;
            }
            
            while(abs(num) >= 9) {
                if(num > 0) {
                    res += 'X';
                    num -= 10;
                } else {
                    res = 'X' + res;
                    num -= 10;
                }
            }
            
            while(num >= 4) {
                res += 'V';
                num -= 5;
            }
            
            while(num > 0 && num < 4) {
                res += 'I';
                --num;
            }
            
            while(num == -1) {
                res = 'I' + res;
                ++num;
            }
        }
        return res;
        */
    }
};

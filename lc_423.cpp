class Solution {
public:
    string originalDigits(string s) {
        unordered_map<string, char> m;
        unordered_map<char, int> countChar;
        unordered_map<int, int> countNum;
        string res;
        
        m["zero"] = '0';
        m["one"] = '1';
        m["two"] = '2';
        m["three"] = '3';
        m["four"] = '4';
        m["five"] = '5';
        m["six"] = '6';
        m["seven"] = '7';
        m["eight"] = '8';
        m["nine"] = '9';
        /*
        z: zero
        x: six
        v: seven five
        w: two
        t: two three eight
        u: four
        r: zero three four
        s: six seven
        n: one seven nine
        o: zero one two four
        h: three eight
        i: five six eight nine
        f: four five
        g: eight
        e: zero one three five seven eight nine
        */
        
        for(char c : s) {
            ++countChar[c];
        }
        
        /*
        countNum[3] = countChar['r'];
        t
        */
        
        countNum[0] = countChar['z'];
        countNum[2] = countChar['w'];
        countNum[4] = countChar['u'];
        countNum[6] = countChar['x'];
        countNum[8] = countChar['g'];
        
        countNum[7] = countChar['s'] - countNum[6];
        countNum[3] = countChar['h'] - countNum[8];
        countNum[5] = countChar['f'] - countNum[4];
        
        countNum[9] = countChar['i'] - countNum[5] - countNum[6] - countNum[8];
        countNum[1] = countChar['n'] - countNum[7] - countNum[9] * 2;
        
        for(int i = 0; i < 10; ++i) {
            //cout << i << ", " << countNum[i] << endl;
            for(int j = 0; j < countNum[i]; ++j) {
                res += '0' + i;
            }
        }
            //cout << endl;
        /*
        res = countNum[0] * '0' +
              countNum[1] * '1' +
              countNum[2] * '2' +
              countNum[3] * '3' +
              countNum[4] * '4' +
              countNum[5] * '5' +
              countNum[6] * '6' +
              countNum[7] * '7' +
              countNum[8] * '8' +
              countNum[9] * '9';
              */
        return res;
    }
};

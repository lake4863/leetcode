class Solution {
private:
    vector<string> result = {"1"};
    void countAS(int n) {
        string s = result.back(); 
        string res = "";
        
        for(int i = 2; i <= n; ++i) {
            s = result.back();
            res = "";
            int cnt = 1;
            for(int j = 0; j < s.length(); ++j) {
                if(j + 1 < s.size() && s[j] != s[j + 1] || j + 1 == s.size()) {
                    res += (cnt + '0');
                    res += s[j];
                    cnt = 1;
                } else {
                    ++cnt;
                }
            }
            
            result.push_back(res);
        }
    }
public:
    string countAndSay(int n) {
        countAS(n);
        
        return result[n - 1];
    }
};

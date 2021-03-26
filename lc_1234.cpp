class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> mp;
        int k = s.length() / 4;
        
        for(char c : s) {
            ++mp[c];
        }
        
        int i=0;
        int result= k * 4;
        for(int j=0;j<k*4;j++){
            --mp[s[j]];
            
            while(i-1<=j && mp['W']<=k && mp['E']<=k && mp['Q']<=k && mp['R']<=k){
                result=min(result,j-i+1);
                mp[s[i]]++;
                i++;
            }
        }
        
        return result;
    }
};
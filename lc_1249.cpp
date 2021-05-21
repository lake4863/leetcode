class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result;
        unordered_set<int> dels;    // record index of parentheses to be kept.
        stack<int> left;
        
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(') {
                left.push(i);
            } else if(s[i] == ')') {
                if(!left.empty()) {
                    dels.insert(left.top());
                    left.pop();
                    dels.insert(i);
                }
            }
        }

        for(int i = 0; i < s.length(); ++i) {
            if(dels.count(i) || !ispunct(s[i])) {
                result += s[i];
            }
        }
        
        return result;
    }
};
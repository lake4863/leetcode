class Solution {
public:
    int scoreOfParentheses(string S) {
        int res = 0, l = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '(') l++; else l--;
            if (S[i] == ')' && S[i - 1] == '(') res += 1 << l;
        }
        return res;
    }
};

/*
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int result = 0;
        
        for(char c : s) {
            if(c == '(') {
                st.push(result);
                result = 0;
            } else {
                result += st.top() + max(result, 1);
                st.pop();
            }
        }
        
        return result;
    }
};
*/
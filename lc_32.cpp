class Solution {
public:
    int longestValidParentheses(string s) {
        unordered_set<int> set;
        stack<int> st;
        int count = 0;
        int maxx = 0;
        char pre = 0;
        //bool in = true;
        //if(!s.size()) return count;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == '(') st.push(i);
            else if(!st.empty()) st.pop();
            else set.insert(i);
        }
        
        while(!st.empty()) {
            set.insert(st.top());
            st.pop();
        }
        
        for(int i = 0; i < s.length(); ++i) {
            if(set.count(i)) {
                count = 0;
            } else if(s[i] == '(') {
                st.push(s[i]);
            } else {
                st.pop();
                count += 2;
                maxx = max(count, maxx);
            }
            //cout << "st.size() = " << st.size() << ", count = " << count << ", s[i] = " << s[i] << endl;
        }
        return maxx;
    }
};
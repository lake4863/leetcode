class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        pair<int, int> p = getGoal(s);
        process(s, "", 0, p.first, p.second, 0);
        vector<string> ret;
        for (auto s : ps) ret.push_back(s);
        return ret;
    }
    
private:
    unordered_set<string> ps;
    
    void process(const string& s, string q, int pos, int tl, int tr, int cl) {
        // boundary
        if (pos == s.size()) {
            if (tl == 0 && tr == 0) ps.insert(q);
            return;
        }
        if (cl < 0) return;
        if (tl < 0 || tr < 0) return;
        char c = s[pos];
        if (c != '(' && c != ')') {
            q += c;
            process(s, q, pos+1, tl, tr, cl);
        }
        else {
            process(s, q+c, pos+1, tl, tr, cl +  (c == '(' ? 1 : -1)); // take
            process(s, q, pos+1, tl- (c == '(' ? 1 : 0), tr - (c == '(' ? 0 : 1), cl); // remove
        }
    }
    
    pair<int, int> getGoal(const string& s) {
        int a = 0, b = 0;
        for (auto c : s) {
            if (c == '(') {
                a ++;
            } else if (c == ')') {
                if (a == 0) {
                    b ++;
                } else a --;
            }
        }
        return make_pair(a, b);
    }
};
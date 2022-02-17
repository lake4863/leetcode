class Solution {
private:
    vector<string> ans;
    void f(int n, string slate, int open, int close) {
        if (open > close) f(n, slate + ")", open, close + 1);
        if (open < n) f(n, slate + "(", open + 1, close);
        if (close == n) ans.push_back(slate);
    }
public:
    vector<string> generateParenthesis(int n) {
        f(n, "", 0, 0);
        return ans;
    }
};

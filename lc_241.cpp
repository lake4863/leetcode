class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        int n = expression.length();
        
        for(int i = 0; i < n; ++i) {
            char c = expression[i];
            if(ispunct(c)) {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for(int l : left) {
                    for(int r : right) {
                        if(c == '+') {
                            res.push_back(l + r);
                        } else if(c == '*') {
                            res.push_back(l * r);
                        } else {
                            res.push_back(l - r);
                        }
                    }
                }
            }
        }
        
        if(res.empty()) {
            res.push_back(stoi(expression));
        }
        
        return res;
    }
};
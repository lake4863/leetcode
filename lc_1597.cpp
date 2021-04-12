list<Node*> op(const list<Node*> &l, char op1, char op2) {
    list<Node*> l1;
    for (auto it = begin(l); it != end(l); ++it) {
        auto o = *it;
        if (o->left == nullptr && (o->val == op1 || o->val == op2)) {
            o->left = l1.back();
            o->right = *next(it);
            l1.back() = o;
            ++it;
        }
        else
            l1.push_back(o);
    }        
    return l1;
}
Node* expTree(string s) {
    list<Node*> l;
    for (auto i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            int j = i + 1;
            for (int bal = 1; bal > 0; ++j)
                bal += s[j] == ')' ? -1 : s[j] == '(' ? 1 : 0;
            l.push_back(expTree(s.substr(i + 1, j - i - 2)));
            i = j - 1;
        }
        else
            l.push_back(new Node(s[i]));
    }
    return op(op(l, '*', '/'), '+', '-').front();
}
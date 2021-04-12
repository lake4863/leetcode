/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
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
            else {
                l1.push_back(o);
            }
        }        
        return l1;
    }
public:
    Node* expTree(string s) {
        vector<list<Node*>> sl(1);
        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                sl.push_back(list<Node*>());
            else if (s[i] == ')') {
                auto root = op(op(sl.back(), '*', '/'), '+', '-').front();
                sl.pop_back();
                sl.back().push_back(root);
            }
            else
                sl.back().push_back(new Node(s[i]));
        }
        return op(op(sl.back(), '*', '/'), '+', '-').front();
    }
};
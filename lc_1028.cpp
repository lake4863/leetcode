/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        int cntdp = 0;
        int dep = 0;
        bool inword = false;
        bool incount = true;
        string num;
        stack<TreeNode*> s;
        
        //cout << "\n\n";
        for(char c : S) {
            if(isdigit(c)) {
                if(incount) {
                    //cout << "dep = " << cntdp;
                    dep = cntdp;
                    //deps.push_back(cntdp);
                }
                cntdp = 0;
                num += c;
                inword = true;
                incount = false;
            } else  {
                ++cntdp;
                if(inword) {
                    //cout << ", num = " << num << endl;
                    build(s, stoi(num), dep);
                    //vals.push_back(stoi(num));
                    num = "";
                }
                inword = false;
                incount = true;
            }
        }
        //cout << ", num = " << num << endl;
        build(s, stoi(num), dep);
        //cout << s.size() << "----------------------------" << endl;
        
        while(s.size() > 1) s.pop();
        
        //cout << s.size() << "----------------------------" << endl;
        //cout << s.top()->val << "----------------------------" << endl;
        return s.top();
    }
    
    void build(stack<TreeNode*>& s, int val, int dep) {
        //cout << "---" << val << ", " << dep << endl;
        while(s.size() > dep) s.pop();
        
        //cout << "---" << s.size() << ", " << dep << endl;
        TreeNode* node = new TreeNode(val);
        if(!s.empty()) {
            if(s.top()->left != nullptr) {
                s.top()->right = node;
            } else {
                s.top()->left = node;
            }
        }
        s.push(node);
        //cout << "---" << s.size() << ", " << dep << endl;
    }
};

class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        TreeNode* root = nullptr;
        int cntdp = 0;
        bool inword = false;
        bool incount = true;
        string num;
        vector<int> deps;
        vector<int> vals;
        
        cout << "\n\n";
        for(char c : S) {
            if(isdigit(c)) {
                if(incount) {
                    cout << "dep = " << cntdp;
                    deps.push_back(cntdp);
                }
                cntdp = 0;
                num += c;
                inword = true;
                incount = false;
            } else  {
                ++cntdp;
                if(inword) {
                    cout << ", num = " << stoi(num) << endl;
                    //build(root, stoi(num), cntdp);
                    vals.push_back(stoi(num));
                    num = "";
                }
                inword = false;
                incount = true;
            }
        }
        cout << ", num = " << num;
        
        //build(root, vals, deps, 0);
        return build(0, deps, vals);
    }
    
    TreeNode* build(int i, vector<int> deps, vector<int> vals){
        int n = deps.size();
        
        if(i == n) return nullptr; 
        TreeNode* temp = new TreeNode(vals[i]) ;
        if(i == n - 1) {
            i++;
            return temp; // because i + 1 == n and deps[n] is not defined
        }
        int prev_node = i ; // root index
        if( deps[i+1] == deps[i] + 1 ) // checking if the next element is left child
            temp->left = build(++i, deps, vals) ;
        else {
            i++; // if no left child then no other child is possible so increment index
            return temp ; 
        }
        if( i == n  )return temp ;// because i == n and deps[n] is not defined
        if( deps[i] == deps[prev_node] + 1 )// checking if the next element is right child
            temp->right = build(i, deps, vals) ;
        return temp ;
    }
};
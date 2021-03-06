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
        stack<TreeNode*> s;
        
        for(int i = 0, dep, val; i < S.length(); ) {
            for(dep = 0; S[i] == '-'; ++i) {
                ++dep;
            }
            for(val = 0; i < S.length() && S[i] != '-'; ++i) {
                val = val * 10 + S[i] - '0';
            }
            while(s.size() > dep) s.pop();
            TreeNode* node = new TreeNode(val);
            if(!s.empty()) {
                if(s.top()->left) {
                    s.top()->right = node;
                } else {
                    s.top()->left = node;
                }
            }
            s.push(node);
        }
        
        while(s.size() > 1) s.pop();
        
        return s.top();
    }
};

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

class Solution {
public:
    TreeNode* recoverFromPreorder(string &S,int &i,int d)
    {
        TreeNode* root=new TreeNode(-1);
        int start=S.find_first_of("1234567890",i);                              //Get index of the first number after i
        if(start-i==d)                                           //If number of '-' in between = depth create root with the integer after it
        {
            i=start;
            start=S.find("-",i);
        }
        else                                                    //Since depth is not correct to add the integer return NULL;
            return NULL;
        root->val=stoi(S.substr(i,start-i));                    //Set the correct root value
        i=start;                                                //Move index forward
        root->left=recoverFromPreorder(S,i,d+1);                //Create left subtree
        root->right=recoverFromPreorder(S,i,d+1);               //Create right subtree
        return root;
    }
    TreeNode* recoverFromPreorder(string S)
    {
        int i=S.find("-");
        TreeNode* root=new TreeNode(stoi(S.substr(0,i)));       //Get first integer and store it as root
        root->left=recoverFromPreorder(S,i,1);                  //Create left subtree
        root->right=recoverFromPreorder(S,i,1);                 //Create right subtree
        return root;
    }
};

class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        if (S.empty()) return nullptr;
        auto pos = 0;
        return decode(S, pos, 0);
    }
    
private:
    TreeNode *decode(const std::string &s, int &pos, int dashCount) {
        if (pos >= s.size()) return nullptr;
        auto curPos = pos;
        while (curPos < s.size() && s[curPos] == '-') ++curPos;
        if (curPos - pos != dashCount) return nullptr;
        int val = 0;
        for(; curPos < s.size() && s[curPos] != '-'; ++curPos)
            val = val * 10 + s[curPos] - '0';
        auto node = new TreeNode(val);
        pos = curPos;
        node->left = decode(s, pos, dashCount + 1);
        node->right = decode(s, pos, dashCount + 1);
        return node;
    }
};
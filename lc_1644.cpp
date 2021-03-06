/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(!isAncestor(root, p) || !isAncestor(root, q)) return nullptr;
        /*
        bool pch = isAncestor(root, p);
        bool qch = isAncestor(root, q);
        // cout << p->val << ", " << pch << " == " << false << ", " << true << " == " << qch << ", " << q->val << endl;
        if(!pch || !qch) return nullptr;
        */
        // if(p == root && q == root) return root;
        
        return lca(root, p, q);
    }
    
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || p == root || q == root) return root;
        TreeNode* lhs = lca(root->left, p, q);
        TreeNode* rhs = lca(root->right, p, q);
        
        if(!lhs) return rhs;
        if(!rhs) return lhs;
        return root;
    }
    
    bool isAncestor(TreeNode* parent, TreeNode* isch) {
        if(!parent) return false;
        if(parent->val == isch->val) return true;
        
        bool lch = isAncestor(parent->left, isch);
        bool rch = isAncestor(parent->right, isch);
        
        if(lch || rch) return true;
        return false;
    }
};

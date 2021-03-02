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
        if(root) {
            bool lp = isAncestor(root->left, p);
            bool lq = isAncestor(root->left, q);
            bool rp = isAncestor(root->right, p);
            bool rq = isAncestor(root->right, q);
            
            if(lp && lq) {
                return lowestCommonAncestor(root->left, p, q);
            } 
	    if(rp && rq) {
                return lowestCommonAncestor(root->right, p, q);
            }
        }
        return root;
    }
    
    bool isAncestor(TreeNode* parent, TreeNode* p) {
        if(!parent) return false;
        bool isleft = isAncestor(parent->left, p);
        bool isright = isAncestor(parent->right, p);
            
        if(parent != p) {
            return isleft || isright;
        }
        return true;
    }
};

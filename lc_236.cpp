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
//                cout << "root->left->val = " << root->left->val << ", isAn(left) = " << isAncestor(root->left, p) << ", isAn(right) = " << isAncestor(root->left, q) << endl;
                return lowestCommonAncestor(root->left, p, q);
            } else if(rp && rq) {
                return lowestCommonAncestor(root->right, p, q);
            } else {
                return root;
            }
        } else {
            return root;
        }
    }
    
    bool isAncestor(TreeNode* parent, TreeNode* p) {
        if(!parent) return false;
        bool isleft = isAncestor(parent->left, p);
        bool isright = isAncestor(parent->right, p);
            
        if(parent == p) {
            return true;
        } else {
            return isleft || isright;
        }
    }
};

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
    int findDistance(TreeNode* root, int p, int q) {
        int dis = -1;
        
        TreeNode* lca = lowestCommonAncestor(root, p, q);
        
        dis = distance(lca, p) + distance(lca, q);
        
        return dis;
    }
    
    int distance(TreeNode* ca, int t) {
        if(!ca) return -1;
        int dist = -1;
        if ((ca->val == t) || 
	    (dist = distance(ca->left, t)) >= 0 || 
	    (dist = distance(ca->right, t)) >= 0) {
            return dist + 1;
        }
        return dist;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
        if(!root || p == root->val || q == root->val) return root;
        
        TreeNode* lhs = lowestCommonAncestor(root->left, p, q);
        TreeNode* rhs = lowestCommonAncestor(root->right, p, q);
        
        if(!lhs) return rhs;
        if(!rhs) return lhs;
        return root;
    }
};

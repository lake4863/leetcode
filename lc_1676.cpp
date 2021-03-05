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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        TreeNode* result = nodes[0];
        
        for(int i = 1; i < nodes.size(); ++i) {
            result = lca2(root, result, nodes[i]);
        }
        
        return result;
    }
    
    TreeNode* lca2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || p == root || q == root) return root;
        
        TreeNode* lhs = lca2(root->left, p, q);
        TreeNode* rhs = lca2(root->right, p, q);
        
        if(!lhs) return rhs;
        if(!rhs) return lhs;
        return root;
    }
};

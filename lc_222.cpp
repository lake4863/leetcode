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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return traverse(root) + 1;
    }
    
    int traverse(TreeNode* root) {
        if(!root) return 0;
        
        int left = 0; 
        int right = 0;
        
        if(root->left) {
            left = traverse(root->left) + 1;
        }
        
        if(root->right) {
            right = traverse(root->right) + 1;
        }
        
        return left + right; 
    }
};
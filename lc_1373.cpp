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
    struct S {
        int sum;
        bool isBST;
        int maxV;
        int minV;
    };
    
    S traverse(TreeNode* root, int& res) {
        if(!root) return { 0, true, INT_MIN, INT_MAX };
        
        S l = traverse(root->left, res);
        S r = traverse(root->right, res);
        
        if(l.isBST && r.isBST && root->val > l.maxV && root->val < r.minV) {
            int tempSum = l.sum + r.sum + root->val;
            res = max(res, tempSum);
            return { tempSum, true, max(root->val, r.maxV), min(root->val, l.minV) };
        } else {
            return { root->val, false, root->val, root->val };
        }
    }
public:
    int maxSumBST(TreeNode* root) {
        int res = 0;
        traverse(root, res);
        return res;
    }
};

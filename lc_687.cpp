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
private:
    TreeNode* pre = nullptr;
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int len = 0;
        traverse(root, len);
        return len;
    }
    
    int traverse(TreeNode* root, int& len) {
        if(!root) return 0;
        int l = traverse(root->left, len);
        int r = traverse(root->right, len);
        
        if(root->right && root->right->val == root->val) {
            ++r;
        } else {
            r = 0;
        }
        
        if(root->left && root->left->val == root->val) {
            //cout << root->val << "\tpre = " << pre->val << endl;
            ++l;
        } else {
            l = 0;
        }
        len = max(len, l + r);
        
        return max(l, r);
    }
};
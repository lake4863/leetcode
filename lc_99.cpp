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
    void recoverTree(TreeNode* root) {
        TreeNode* pre = nullptr;
        TreeNode* begin = nullptr;
        TreeNode* end = nullptr;
        
        traverse(root, pre, begin, end);
        //cout << "begin = " << begin->val << ", end = " << end->val << endl;
        swap(begin->val, end->val);
    }
    
    void traverse(TreeNode* root, TreeNode*& pre, TreeNode*& begin, TreeNode*& end) {
        if(!root) return;
        
        traverse(root->left, pre, begin, end);
        
        if(pre && (root->val < pre->val)) {
            if(!begin) begin = pre;
            end = root;
        }
        pre = root;
        
        traverse(root->right, pre, begin, end);
    }
    /*
    TreeNode* search(TreeNode* root) {
        if(!root || !root->left || !root->right) return nullptr;
        TreeNode* ab;
        
        if(root->val < root->left->val) return root;
        if(root->val > root->right->val) return root;
        if(!root->left) return search(root->right);
        if(!root->right) return search(root->left);
        
        return ab;
    }
    */
};
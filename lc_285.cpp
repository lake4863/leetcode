class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        queue<TreeNode*> s;
        traverse(s, root);
        while(s.front() != p) s.pop();
        s.pop();
        return s.empty() ? nullptr : s.front();
    }
    
    void traverse(queue<TreeNode*>& s, TreeNode* root) {
        if(!root) return;
        traverse(s, root->left);
        s.push(root);
        traverse(s, root->right);
    }
};

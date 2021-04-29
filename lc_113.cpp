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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        findPaths(root, sum, path, paths);
        return paths;  
    }
private:
    void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
        if (!node) return;
        path.push_back(node -> val);
        if (!(node -> left) && !(node -> right) && sum == node -> val)
            paths.push_back(path);
        findPaths(node -> left, sum - node -> val, path, paths);
        findPaths(node -> right, sum - node -> val, path, paths);
        path.pop_back();
    }
};
/*
class Solution {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int n = count(root, targetSum, 0);
        
        if(!n) return result;
        
        cout << n << endl;
        
        for(int i = 0; i < n; ++i) {
            result.push_back({ root->val });
        }
        
        
        return result;
    }
    
    int count(TreeNode* root, int target, int dep) {
        if(!root) return 0;
        target -= root->val;
        if(!target) return 1;
        
        int left = count(root->left, target, dep + 1);
        int right = count(root->right, target, dep + 1);
        cout << "dep = " << dep << ", left = "<< left << ", right = " << right << "; \t ";
        cout << "root = " << root->val << ", left = "<< root->left->val << ", right = " << root->right->val << endl;
        
        return left + right;
    }
};
*/
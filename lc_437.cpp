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
    vector<int> path;
    vector<vector<int>> paths;
    int count = 0;
public:
    int pathSum(TreeNode* root, int sum) {
        traverse(root, sum);
        return count;
    }
    
    void traverse(TreeNode* root, int sum) {
        if(!root) return;
        utility(root, sum);
        traverse(root->left, sum);
        traverse(root->right, sum);
    }
    
    void utility(TreeNode* root, int sum) {
        if(!root) return;
        //path.push_back(root->val);
        if(root->val == sum) {
            //paths.push_back(path);
            ++count;
        }
        utility(root->left, sum - root->val);
        utility(root->right, sum - root->val);
        //path.pop_back();
    }
};

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
    vector<int> path;
    vector<vector<int>> paths;
public:
    int pathSum(TreeNode* root, int sum) {
        traverse(root, sum);
        return paths.size();
    }
    
    void traverse(TreeNode* root, int sum) {
        if(!root) return;
        utility(root, sum);
        traverse(root->left, sum);
        traverse(root->right, sum);
    }
    
    void utility(TreeNode* root, int sum) {
        if(!root) return;
        path.push_back(root->val);
        if(root->val == sum) {
            paths.push_back(path);
        }
        utility(root->left, sum - root->val);
        utility(root->right, sum - root->val);
        path.pop_back();
    }
};
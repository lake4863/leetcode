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
    vector<long> sums;
public:
    int maxProduct(TreeNode* root) {
        long totalSum = treeSum(root);
        long best = 0;
        for(auto i : sums) {
            best = max(best, i * (totalSum - i));
        }
        
        return (int)(best % (long)(1e9 + 7));
    }
    
    int treeSum(TreeNode* subroot) {
        if(!subroot) return 0;
        
        int left = treeSum(subroot->left);
        int right = treeSum(subroot->right);
        int total = left + right + subroot->val;
        sums.push_back(total);
        return total;
    }
};

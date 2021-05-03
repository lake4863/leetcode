/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> result;
        vector<TreeNode*> path(1001);    // record all the nodes from root to target
        int deptar = -1;
        int n = 0;
        
        if(!K) return { target->val };
        
        tra(root, target, 0, deptar, path);
        //cout << deptar << endl;
        for(auto i : path) {
            if(i) {
                //cout << "find the path to target = "<< i->val << endl;
                ++n;
            }
        }
        if(K < n) {
            return { path[n - 1 - K]->val };
        }
        
        for(int i = 0; i < n - 1; ++i) {
            if(path[i]->left == path[i + 1]) {
                traverse(root->right, K - n + i, path[i], result);
            } else {
                //cout << i << " = i" << endl;
                traverse(root->left, K - n + i, path[i], result);
            }
        }
            //cout << K - deptar << " *** " << path[n - 1]->val << endl;
        traverse(path[n - 1], K - deptar + 1, nullptr, result);
        
        return result;
    }
    
    void tra(TreeNode* root, TreeNode* target, int dep, int& deptar, vector<TreeNode*>& path) {
        if(!root) return;
        static vector<TreeNode*> paths;
        paths.push_back(root);
        if(root == target) {
            deptar = dep;
            copy(paths.begin(), paths.end(), path.begin());
        } 
        tra(root->left, target, dep + 1, deptar, path);
        tra(root->right, target, dep + 1, deptar, path);
        paths.pop_back();
    }
    
    void traverse(TreeNode* root, int K, TreeNode* nextNode, vector<int>& result) {
        if(!root) return;
        if(!K) result.push_back(root->val);
        
        traverse(root->left, K - 1, nextNode, result);
        traverse(root->right, K - 1, nextNode, result);
    }
};
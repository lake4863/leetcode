class Solution {
private:
    vector<int> nodes;
    int i = 0;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        return traverse(root, voyage) ? nodes : vector<int>{ -1 };
    }
    
    bool traverse(TreeNode* root, vector<int>& v) {
        if(!root) return true;
        
        if(root->val != v[i++]) return false;
        if(root->left && root->left->val != v[i]) {
            nodes.push_back(root->val);
            if(root->right) {
                swap(root->left, root->right);
            }
        }
        
        return traverse(root->left, v) && traverse(root->right, v);
    }
};

class Solution {
private:
	vector<int> res;
    int i = 0;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& v) {
        return dfs(root, v) ? res : vector<int>{-1};
    }

    bool dfs(TreeNode* node, vector<int>& v) {
        if (!node) return true;
        if (node->val != v[i++]) return false;
        if (node->left && node->left->val != v[i]) {
            res.push_back(node->val);
            return dfs(node->right, v) && dfs(node->left, v);
        }
        return dfs(node->left, v) && dfs(node->right, v);
    }
};
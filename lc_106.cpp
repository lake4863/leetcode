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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return bld(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
    
    TreeNode* bld(vector<int>&inorder, vector<int>&postorder, int istart, int iend,
                  int pstart,int pend){
        if(istart > iend || pstart > pend)
            return NULL;
        int val = postorder[pend];
        
        int i = istart;
        while(inorder[i] != val) i++;

        TreeNode* root = new TreeNode(val);
        root->left = bld(inorder, postorder, istart, i-1, pstart, pstart+i-istart-1);
        root->right = bld(inorder, postorder, i+1, iend, pend-(iend-i), pend-1);
        return root;
    }
};

// need try to debug two versions below
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> m;
        for(int i = 0; i < inorder.size(); ++i) m[inorder[i]] = i;
        return helper(postorder, m, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    
    TreeNode* helper(vector<int>& post, unordered_map<int, int> inIndex, int inLeft, int inRight, int postLeft, int postRight) {
        if(inLeft > inRight) return nullptr;
        TreeNode* node = new TreeNode(post[postRight]);
        int inMid = inIndex[post[postRight]];
        node->left = helper(post, inIndex, inLeft, inMid - 1, postLeft, postLeft + inMid - inLeft - 1);
        node->right = helper(post, inIndex, inMid + 1, inRight, postRight + inMid - inRight, postRight - 1);
        return node;
    }
};

class Solution {
private:
    // start and end variables indicate the start of the inorder index and the end of the inorder index respectively. 
    TreeNode *helper(vector<int> &postorder, vector<int> &inorder, int start, int end, int &index, unordered_map<int, int> &dict) {
        if (start < end) return NULL;
        TreeNode* node= new TreeNode(postorder[index]);
        int i = dict[postorder[index--]];
        cout << node->val << ", ";
        node -> right = helper(postorder, inorder, i + 1, start, index, dict);
        node -> left = helper(postorder, inorder, end, i - 1, index, dict);
    
        return node;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size() - 1;
        unordered_map<int, int> dict;
        
        // Store all the inorder indices to get start and end for each node's left and right nodes
        for (int i = 0; i < inorder.size(); ++i) 
            dict[inorder[i]] = i;
        
        
        return helper(postorder, inorder, postorder.size() - 1, 0, index, dict);
    }
};
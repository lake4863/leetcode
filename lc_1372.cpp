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
    int res = 0;
public:
    int longestZigZag(TreeNode* root) {
        //if(!root->left && !root->right) return 0;
        longestZZ(root, true);

        return res;
    }

    int longestZZ(TreeNode* root, bool isleft) {
        if(!root) return -1;

        /*
        int l = longestZZ(root->left, !isleft);
        int r = longestZZ(root->right, isleft);
        */
        int l = longestZZ(root->left, false);
        int r = longestZZ(root->right, true);

        res = max(res, max(l + 1, r + 1));

        return isleft ? l + 1 : r + 1;
        /*
        if(isleft) {
            if(!root->right) {
                return 0;
            } else {
                return longestZZ(root->right, !isleft) + 1;
            }
        } else {
            if(!root->left) {
                return 0;
            } else {
                return longestZZ(root->left, isleft) + 1;
            }
        }
        */
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
    void traverse(TreeNode *root, bool leftToRight, int &ans, int currLength)
    {
        if (root == NULL)
        {
            return;
        }

        ans = max(ans, currLength);

        if (leftToRight)
        {
            traverse(root->right, !leftToRight, ans, currLength + 1);  // option 1
            traverse(root->left, leftToRight, ans, 1);                 // option 2
        }
        else
        {
            traverse(root->left, !leftToRight, ans, currLength + 1); // option 1
            traverse(root->right, leftToRight, ans, 1);              // option 2
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        traverse(root, true, ans, 0);
        return ans;
    }
};

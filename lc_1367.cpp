/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSP(ListNode* head, TreeNode* root, bool is_consecutive) {
        if(!root) return false;
        if(!head) return true;
        
        if(is_consecutive) {
            if(head->val != root->val) {
                return false;
            }
            return isSP(head->next, root->left, true) || isSP(head->next, root->right, true);
        }
        return isSP(head, root, !is_consecutive) || isSP(head, root->left, !is_consecutive) || isSP(head, root->right, !is_consecutive);
        /*
        if(root->val == head->val) {
            if(!head->next) {
                return true;
            } else {
                head = head->next;
            }
        }
        isSubPath(head, root->left);
        isSubPath(head, root->right);
        
        return false;
        */
    }
public:
    bool dfs(ListNode* head, TreeNode* root) {
        if(!head) return true;
        if(!root) return false;
        
        return head->val == root->val && (dfs(head->next, root->left) || dfs(head->next, root->right));
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head) return true;
        if(!root) return false;
        
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
    
};

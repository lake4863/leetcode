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
class Solution {
private:
    ListNode* swapTwo(ListNode* head) {
        if(head) {
           if(head->next) {
               ListNode* first = head;
               ListNode* second = head->next;
               
               first->next = swapTwo(head->next->next);
               second->next = first;

               return second;
           } else {
               return head;
           }
        } else {
            return nullptr;
        }
    }
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode newHead = ListNode(0);
        newHead.next = swapTwo(head);
        
        return newHead.next;
    }
};

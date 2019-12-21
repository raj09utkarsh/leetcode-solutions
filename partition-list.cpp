/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = NULL;
        ListNode* leftItr = NULL;
        ListNode* right = NULL;
        ListNode* rightItr = NULL;
        
        ListNode* temp = head;
        
        while(temp!=NULL){
            if(temp->val < x){
                if(left == NULL){
                    left = temp;
                    leftItr = temp;
                }
                else{
                    leftItr->next = temp;
                    leftItr = leftItr->next;
                }
            }
            else{
                if(right == NULL){
                    right = temp;
                    rightItr = temp;
                }
                else{
                    rightItr->next = temp;
                    rightItr = rightItr->next;
                }
            }
            temp = temp->next;
        }
        if(leftItr == NULL){
            return right;
        }
        if(rightItr == NULL){
            return left;
        }
        leftItr->next = right;
        rightItr->next = NULL;
        return left;
    }
};
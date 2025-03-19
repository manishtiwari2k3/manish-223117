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
public:
    ListNode* reverseLL(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* newh = reverseLL(head->next);
        ListNode* front = head->next;
        front->next=head;
        head->next=NULL;
        return newh;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newh = reverseLL(slow->next);
        ListNode* first = head;
        ListNode* second = newh;
        while(second!=NULL){
            if(first->val!=second->val){
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;
    }
};
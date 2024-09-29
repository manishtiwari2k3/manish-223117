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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode* temp = head;
        // int cnt = 0;
        // while(temp!=NULL){
        //     cnt++;
        //     temp=temp->next;
        // }
        // int res = cnt-n;
        // if(cnt==n){
        //     ListNode* newH = head->next;
        //     delete(head);
        //     return newH;
        // }
        // temp = head;
        // while(temp){
        //     res--;
        //     if(res==1){
        //         break;
        //     }
        //     temp = temp->next;                      wrong
        // }
        // ListNode* del = temp->next;
        // temp->next = temp->next->next;
        // delete(del);

        // return head;





        // ListNode* temp = head;
        // int cnt = 0;
        // while(temp){
        //     cnt++;
        //     temp = temp->next;
        // }
        // temp = head;
        // if(cnt==n){
        //     ListNode* newH = temp->next;
        //     delete(head);
        //     return newH;
        // }
        // int res = cnt-n;
        // while(temp){
        //     res--;
        //     if(res==0){
        //         break;
        //     }
        //     temp = temp->next;
        // }
        // ListNode* del = temp->next;
        // temp->next = temp->next->next;
        // delete(del);
        // return head;


        // optimal


        ListNode * fast = head;
        ListNode* slow = head;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        if(fast==NULL){
            return head->next;
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow = slow->next;
        }
        ListNode* del = slow->next;
        slow->next = slow->next->next;
        delete(del);
        return head;
    }
};
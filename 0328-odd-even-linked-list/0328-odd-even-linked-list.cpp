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
    ListNode* oddEvenList(ListNode* head) {
        // if(head==NULL||head->next==NULL){
        //     return head;
        // }
        // vector <int> arr = {};
        // ListNode* temp = head;
        // while(temp!=NULL && temp->next!=NULL){
        //     arr.emplace_back(temp->val);
        //     temp=temp->next->next;
        // }
        // if(temp){
        //     arr.emplace_back(temp->val);
        // }
        // temp = head->next;
        // while(temp!=NULL && temp->next!=NULL){
        //     arr.emplace_back(temp->val);
        //     temp = temp->next->next;
        // }
        // if(temp){
        //     arr.emplace_back(temp->val);
        // }

        // int i=0 ;
        // temp = head;
        // while(temp){
        //     temp->val = arr[i];
        //     temp  = temp->next;
        //     i++;
        // }
        // return head;


        // optimal

        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenH = head->next;
        while(even!=NULL && even->next!=NULL)//because even is always ahead of odd so we dont have to check for the odd separately
        {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }
        odd->next = evenH;
        return head;
    }
};
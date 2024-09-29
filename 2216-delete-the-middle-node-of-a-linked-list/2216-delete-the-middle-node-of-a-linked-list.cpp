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
    ListNode* deleteMiddle(ListNode* head) {
        // if(head==NULL||head->next==NULL){
        //     return nullptr;
        // }
        // ListNode* slow = head;
        // ListNode* fast = head;
        // while(fast->next!=NULL&&fast->next->next!=NULL){
        //     fast = fast->next->next;
        //     slow = slow->next;
        // }
        // ListNode* del = slow->next;
        // slow->next=slow->next->next;
        // delete(del);
        // return head;



        ListNode* temp = head;
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        int cnt= 0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        temp = head;
        int res = cnt/2;
        while(temp){
            res--;
            if(res==0){
                break;
            }
            temp = temp->next;
        }
        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete(del);
        return head;
    }
};
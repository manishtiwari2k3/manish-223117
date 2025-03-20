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
        ListNode* temp = head;
        ListNode* back = nullptr;
        while(temp){
            ListNode* front = temp->next;
            temp->next = back;
            back = temp;
            temp = front;
        }
        return back;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newh = reverseLL(head);
        ListNode* temp = newh;
        ListNode* prev = nullptr;
        int count = 0;
        while(temp){
            count++;
            if(count == n){
                if(prev==nullptr){
                    newh = temp->next;
                }
                else{
                    prev->next = temp->next;
                }
            }
            prev = temp;
            temp = temp->next;
        }
        return reverseLL(newh);
    }
};
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
    ListNode* reverseList(ListNode* head) {
        // ListNode* temp = head;
        // stack <int> st;
        // while(temp){
        //     st.push(temp->val);
        //     temp = temp->next;
        // }
        // temp = head;
        // while(temp){
        //     temp->val = st.top();
        //     st.pop();
        //     temp = temp->next;
        // }
        // return head;

        //     if(head==NULL || head->next==NULL){
        //         return head;
        //     }
        //     ListNode* temp = head;
        //     ListNode* prev = NULL;
        //     while(temp != NULL){
        //         ListNode* front = temp->next;
        //         temp->next = prev;
        //         prev = temp;
        //         temp = front;
        //     }
        // return prev;

        // if(head==NULL || head->next==NULL){
        //     return head;
        // }
        // ListNode* temp = head;
        // ListNode* prev = NULL;
        // while(temp!=NULL){
        //     ListNode* front = temp->next;
        //     temp->next = prev;
        //     prev = temp;
        //     temp = front;
        // }
        // return prev;

        // // recursive approach
        

        // // ListNode* reverseLL(ListNode* head) {
        //     if (head == NULL || head->next == NULL) {
        //         return head;
        //     }
        //     ListNode* newH = reverseList(head->next);

        //     ListNode* front = head->next;
        //     front->next = head;
        //     head->next = NULL;

        //     return newH;
        // // }
        

        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* newH = reverseList(head->next);

        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newH;
    }
};
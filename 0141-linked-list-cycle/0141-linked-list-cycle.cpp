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
    bool hasCycle(ListNode *head) {
        // map <ListNode* , int> mpp;
        // ListNode* temp = head;
        // while(temp!=NULL){
        //     if(mpp.find(temp)!=mpp.end()){
        //         return true;
        //     }
        //     mpp[temp] = 1;
        //     temp = temp->next;
        // }
        // return false;




        // map <ListNode* , int> mpp;
        // ListNode* temp = head;
        // while(temp!=NULL){
        //     if(mpp.find(temp)!=mpp.end()){
        //         return true;
        //     }
        //     mpp[temp] = 1;
        //     temp = temp->next;
        // }
        // return false;



        // optimal

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            // if(fast==slow){
            //     return true;
            // }
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
    }
};
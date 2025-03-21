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
    ListNode* convertArr2LL(vector<int> &arr){
        ListNode* head = new ListNode(arr[0]);
        ListNode* mover = head;
        for(int i=1;i<arr.size();i++){
            ListNode* front = new ListNode(arr[i]);
            mover->next = front;
            mover = front;
        }
        return head;
    }
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        if(head==NULL || head->next==NULL){
            return head;
        }
        vector<int>arr;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(),arr.end());
        ListNode* newh = convertArr2LL(arr);
        return newh;
    }
};
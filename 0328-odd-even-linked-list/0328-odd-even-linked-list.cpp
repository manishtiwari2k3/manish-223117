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
    ListNode* convertArr2LL(vector<int>& arr){
        if(arr.empty()){
            return nullptr;
        }
        ListNode* head = new ListNode(arr[0]);
        ListNode* mover = head;
        for(int i=1;i<arr.size();i++){
            // mover->next = new ListNode(arr[i]);
            // mover = mover->next;
            ListNode* temp = new ListNode(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return head;
    }
    ListNode* oddEvenList(ListNode* head) {
        vector<int>arr;
        ListNode* temp = head;
        while(temp){
            arr.emplace_back(temp->val);
            temp= temp->next;
        }
        vector<int>oddev;
        for(int i=0;i<arr.size();i+=2){
            oddev.emplace_back(arr[i]);
        }
        for(int i=1;i<arr.size();i+=2){
            oddev.emplace_back(arr[i]);
        }
        ListNode* newh = convertArr2LL(oddev);
        return newh;
    }
};
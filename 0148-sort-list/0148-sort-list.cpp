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
 #include<bits/stdc++.h>
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* temp =head;
        vector <int> arr = {};
        while(temp){
            arr.emplace_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        sort(arr.begin(),arr.end());
        int i = 0;
        while(temp){
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int left = 0;
       int right = 0;
       int index = 0;
       int arr3[m+n];
       while(left<m && right<n){
            if(nums1[left] < nums2[right]){
                arr3[index] = nums1[left];
                index++;
                left++;
            }
            else{
                arr3[index] = nums2[right];
                index++;
                right++;
            }
       }
       while(left<m){
            arr3[index] = nums1[left];
            left++;
            index++;
       }
       while(right<n){
            arr3[index] = nums2[right];
            right++;
            index++;
       }
        for(int i=0;i<m+n;i++){
            nums1[i] = arr3[i];
        }
    }
};
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {


    // int left = 0;
    // int right = 0;
    // int index = 0;
    // int arr3[m+n];
    // while(left<m && right<n){
    //     if(nums1[left]<=nums2[right]){
    //         arr3[index] = nums1[left];
    //         left++;
    //         index++;
    //     }
    //     else{
    //         arr3[index] = nums2[right];
    //         right++;
    //         index++;
    //     }
    // }

    // while(left<m){
    //     arr3[index] = nums1[left];
    //     left++;
    //     index++;
    // }
    // while(right<n){
    //     arr3[index] = nums2[right];
    //     right++;
    //     index++;
    // }


    // for(int i=0;i<m+n;i++){
    //     if(i<m){
    //         nums1[i] = arr3[i];
    //     }
    //     else{
    //         nums2[i-m] = arr3[i];
    //     }
    // }

    // for(int i=0 ; i<m;i++){
    //     if(nums1[i]==0){
    //         continue;
    //     }
    //     else{
    //         cout << nums1[i] <<  " ";
    //     }
    // }
    // for(int i=0 ; i<n;i++){
    //     if(nums2[i]==0){
    //         continue;
    //     }
    //     else{
    //         cout << nums2[i] <<  " ";
    //     }
    // }

    
        if(n == 0) return;
        else if(m==0){
            int i = 0;
            for(auto it: nums2){
                nums1[i++] = it;
            }
            return;
        }
        for(int i = m; i<n+m; i++){
            nums1[i] = nums2[i-m];
        }
        sort(nums1.begin(),nums1.end());
    
    }
};
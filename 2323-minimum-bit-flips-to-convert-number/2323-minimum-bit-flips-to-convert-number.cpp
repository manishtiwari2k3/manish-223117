class Solution {
public:
    int minBitFlips(int start, int goal) {
        // int count = 0;
        // while (start > 0 || goal > 0) {
        //     if ((start & 1) != (goal & 1)) {
        //         count++;
        //     }
        //     start >>= 1;
        //     goal >>= 1;
        // }
        // return count;

        int ans = (start^goal) ;
        int cnt = 0;
        for(int i=0;i<32;i++){
            if((ans & 1<<i)!=0){
                cnt++;
            }
        }
        return cnt;
    }
};
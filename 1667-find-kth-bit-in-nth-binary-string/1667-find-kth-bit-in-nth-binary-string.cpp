// class Solution {
// public:
//     char findKthBit(int n, int k) {
//         string sequence = "0";
//         for (int i = 1; i < n && k > sequence.length(); ++i) {
//             sequence += '1';
//             string temp = sequence;
//             for (int j = temp.length() - 2; j >= 0; --j) {
//                 char invertedBit = (temp[j] == '1') ? '0' : '1';
//                 sequence += invertedBit;
//             }
//         }
//         return sequence[k - 1];
//     }
// };

// class Solution {
// public:
//     char findKthBit(int n, int k) {
//         if (n == 1) return '0';
//         int len = 1 << n;  
//         if (k < len / 2) {
//             return findKthBit(n - 1, k);
//         }
//         else if (k == len / 2) {
//             return '1';
//         }
//         else {
//             char correspondingBit = findKthBit(n - 1, len - k);
//             return (correspondingBit == '0') ? '1' : '0';
//         }
//     }
// };




class Solution {
public:
    char findKthBit(int n, int k) {
        int invertCount = 0;
        int len = (1 << n) - 1; 

        while (k > 1) {
            if (k == len / 2 + 1) {
                return invertCount % 2 == 0 ? '1' : '0';
            }
            if (k > len / 2) {
                k = len + 1 - k; 
                invertCount++;    
            }

            len /= 2;  
        }
        return invertCount % 2 == 0 ? '0' : '1';
    }
};
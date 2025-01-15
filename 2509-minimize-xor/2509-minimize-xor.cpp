// class Solution {
// public:
//     int minimizeXor(int num1, int num2) {
//         int result = num1;

//         int targetSetBitsCount = __builtin_popcount(num2);
//         int setBitsCount = __builtin_popcount(result);

//         int currentBit = 0;

//         while (setBitsCount < targetSetBitsCount) {
//             if (!isSet(result, currentBit)) {
//                 setBit(result, currentBit);
//                 setBitsCount++;
//             }
//             currentBit++;
//         }

//         while (setBitsCount > targetSetBitsCount) {
//             if (isSet(result, currentBit)) {
//                 unsetBit(result, currentBit);
//                 setBitsCount--;
//             }
//             currentBit++;
//         }

//         return result;
//     }

// private:
//     bool isSet(int x, int bit) { return x & (1 << bit); }

//     void setBit(int &x, int bit) { x |= (1 << bit); }

//     void unsetBit(int &x, int bit) { x &= ~(1 << bit); }
// };

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int result = 0;

        int targetSetBitsCount = __builtin_popcount(num2);
        int setBitsCount = 0;
        int currentBit = 31;  // Start from the most significant bit.

        // While x has fewer set bits than num2
        while (setBitsCount < targetSetBitsCount) {
            if (isSet(num1, currentBit) ||
                (targetSetBitsCount - setBitsCount > currentBit)) {
                setBit(result, currentBit);
                setBitsCount++;
            }
            currentBit--; 
        }

        return result;
    }

private:
    bool isSet(int x, int bit) { return x & (1 << bit); }

    void setBit(int &x, int bit) { x |= (1 << bit); }
};
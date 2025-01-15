class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // Initialize result to num1. We will modify result.
        int result = num1;

        int targetSetBitsCount = __builtin_popcount(num2);
        int setBitsCount = __builtin_popcount(result);

        // Start with the least significant bit (bit 0).
        int currentBit = 0;

        // Add bits to result if it has fewer set bits than the target.
        while (setBitsCount < targetSetBitsCount) {
            // If the current bit in result is not set (0), set it to 1.
            if (!isSet(result, currentBit)) {
                setBit(result, currentBit);
                setBitsCount++;
            }
            currentBit++;
        }

        while (setBitsCount > targetSetBitsCount) {
            if (isSet(result, currentBit)) {
                unsetBit(result, currentBit);
                setBitsCount--;
            }
            currentBit++;
        }

        return result;
    }

private:
    bool isSet(int x, int bit) { return x & (1 << bit); }

    void setBit(int &x, int bit) { x |= (1 << bit); }

    void unsetBit(int &x, int bit) { x &= ~(1 << bit); }
};
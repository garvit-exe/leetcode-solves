class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0; 
        int exclusiveOR = start ^ goal;

        while (exclusiveOR != 0) {
            ans += exclusiveOR & 1;
            exclusiveOR >>= 1;
        }

        return ans;
    }
};
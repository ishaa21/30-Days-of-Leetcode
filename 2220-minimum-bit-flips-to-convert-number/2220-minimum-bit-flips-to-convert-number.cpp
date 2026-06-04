class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        int ans = start ^ goal;
        while(ans > 1)
        {
            if(ans & 1) count++;
            ans >>= 1;
        }
        if(ans == 1) count++;
        return count;
    }
};
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for (int i = num1; i <= num2; i++) {
            string s = to_string(i);
            int cnt = 0;
            for (int j = 1; j < s.length() - 1; j++) {
                char x = s[j - 1];
                char y = s[j];
                char z = s[j + 1];
                if ((y > x && y > z) || (y < x && y < z)) {
                    cnt++;
                }
            }
            ans += cnt;
        }
        return ans;
    }
};

class Solution {
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;

    Node dp[20][3][11][11];
    bool vis[20][3][11][11];

    Node dfs(int pos,
             bool tight,
             int lenState,
             int prev2,
             int prev1)
    {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][lenState][prev2 + 1][prev1 + 1])
            return dp[pos][lenState][prev2 + 1][prev1 + 1];

        int limit = tight ? (s[pos] - '0') : 9;

        Node ans = {0, 0};

        for (int d = 0; d <= limit; d++) {

            bool ntight = tight && (d == limit);

            if (lenState == 0) {

                // still leading zeros
                if (d == 0) {
                    Node nxt = dfs(pos + 1, ntight, 0, -1, -1);

                    ans.cnt += nxt.cnt;
                    ans.wav += nxt.wav;
                }
                else {
                    Node nxt = dfs(pos + 1, ntight, 1, -1, d);

                    ans.cnt += nxt.cnt;
                    ans.wav += nxt.wav;
                }
            }

            else if (lenState == 1) {

                Node nxt = dfs(pos + 1, ntight, 2, prev1, d);

                ans.cnt += nxt.cnt;
                ans.wav += nxt.wav;
            }

            else {

                int add = 0;

                if ((prev1 > prev2 && prev1 > d) ||
                    (prev1 < prev2 && prev1 < d))
                    add = 1;

                Node nxt = dfs(pos + 1, ntight, 2, prev1, d);

                ans.cnt += nxt.cnt;
                ans.wav += nxt.wav + 1LL * add * nxt.cnt;
            }
        }

        if (!tight) {
            vis[pos][lenState][prev2 + 1][prev1 + 1] = true;
            dp[pos][lenState][prev2 + 1][prev1 + 1] = ans;
        }

        return ans;
    }

    long long solve(long long n) {
        if (n < 0) return 0;

        s = to_string(n);

        memset(vis, 0, sizeof(vis));

        return dfs(0, true, 0, -1, -1).wav;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
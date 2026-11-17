
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size(), INF = 1e9;
        vector<vector<int>> c(n, vector<int>(n, INF));

        for (int l = 2; l <= n; l++)
            for (int i = 0; i + l <= n; i++) {
                int len = l;
                for (int d = 1; d < len; d++) {
                    if (len % d) continue;
                    int cnt = 0;
                    for (int r = 0; r < d; r++)
                        for (int a = i + r,
                                 b = i + r + ((len - 1) / d) * d;
                             a < b; a += d, b -= d)
                            cnt += s[a] != s[b];
                    c[i][i + len - 1] =
                        min(c[i][i + len - 1], cnt);
                }
            }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;

        for (int p = 1; p <= k; p++)
            for (int i = 2 * p; i <= n; i++)
                for (int j = 2 * (p - 1); j <= i - 2; j++)
                    dp[i][p] = min(dp[i][p],
                        dp[j][p - 1] + c[j][i - 1]);

        return dp[n][k];
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
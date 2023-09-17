#include <stdio.h>
#include <limits.h>

#define int long long int
#define INF 1e18 + 9
#define MAXN 1001
#define MAXS1 1001

int ans[MAXS1][MAXN];
int suff[MAXN][MAXN];
int data[MAXN][4];
int x[MAXN], t[MAXN], y[MAXN], r[MAXN];
int v[MAXN];
int dp[MAXS1][MAXN];

signed main() {
    int n, s1, s2;
    scanf("%lld %lld %lld", &n, &s1, &s2);

    for (int i = 0; i < s1; i++) {
        for (int j = 0; j < 1001; j++) {
            ans[i][j] = INF;
        }
    }
    ans[0][0] = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 1001; j++) {
            suff[i][j] = INF;
        }
    }
    suff[n][0] = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %lld %lld", &data[i][0], &data[i][1], &data[i][2], &data[i][3]);
        x[i] = data[i][0];
        t[i] = data[i][1];
        y[i] = data[i][2];
        r[i] = data[i][3];
    }

    for (int i = 0; i < n; i++) {
        v[i] = i;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 1001; j++) {
            if (suff[i + 1][j] != INF) {
                suff[i][j] = suff[i][j] < suff[i + 1][j] ? suff[i][j] : suff[i + 1][j];
                if (y[v[i]] + j <= 1000) {
                    suff[i][y[v[i]] + j] = suff[i][y[v[i]] + j] < suff[i + 1][j] + r[v[i]] ? suff[i][y[v[i]] + j] : suff[i + 1][j] + r[v[i]];
                }
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 1000; j > 0; j--) {
            suff[i][j - 1] = suff[i][j - 1] < suff[i][j] ? suff[i][j - 1] : suff[i][j];
        }
    }

    int min_minutes = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s1; j++) {
            for (int k = 0; k < 1001; k++) {
                dp[j][k] = INF;
            }
        }

        for (int j = 0; j < s1; j++) {
            for (int k = 0; k < 1001; k++) {
                if (ans[j][k] != INF) {
                    if (x[v[i]] + j >= s1) {
                        int temp = ans[j][k] + t[v[i]] + suff[i + 1][s1 + s2 - (x[v[i]] + j) - k > 0 ? s1 + s2 - (x[v[i]] + j) - k : 0];
                        min_minutes = min_minutes < temp ? min_minutes : temp;
                    }
                    if (x[v[i]] + j < s1) {
                        dp[x[v[i]] + j][k] = dp[x[v[i]] + j][k] < ans[j][k] + t[v[i]] ? dp[x[v[i]] + j][k] : ans[j][k] + t[v[i]];
                    }
                    if (y[v[i]] + k <= 1000) {
                        dp[j][y[v[i]] + k] = dp[j][y[v[i]] + k] < ans[j][k] + r[v[i]] ? dp[j][y[v[i]] + k] : ans[j][k] + r[v[i]];
                    }
                }
            }
        }

        for (int j = 0; j < s1; j++) {
            for (int k = 0; k < 1001; k++) {
                ans[j][k] = ans[j][k] < dp[j][k] ? ans[j][k] : dp[j][k];
            }
        }
    }

    if (min_minutes == INF) {
        printf("-1\n");
    } else {
        printf("%lld\n", min_minutes);
    }

    return 0;
}

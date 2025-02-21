#include <bits/stdc++.h>
#define int long long
#define float long double
#define pp pair<int, int>
#define tp tuple<int, int, int>
#define mtp make_tuple
#define mp make_pair
using namespace std;
// using lf = __float128;
// using ld = __int128;
// float pi = 3.141592653589793238462643383279502884197169399375105Q;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int ddx[8] = {0, 0, 1, -1, 1, 1, -1, 1}, ddy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
#define INF 10000000

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    vector<int> MINS(n + 1, 12345);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            MINS[i] = min(MINS[i], arr[i][j]);
            if (i == 1)
                dp[i][j] = arr[i][j];
        }
    }

    int ret = INF;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int before = INF;
            // j로 가야징
            for (int k = 1; k <= m; k++)
            {
                if (j == k)
                    continue;
                before = min(before, dp[i - 1][k]);
            }
            dp[i][j] = before + arr[i][j];
            if (i == n)
                ret = min(dp[i][j], ret);
        }
    }
    cout << ret;

    return 0;
}
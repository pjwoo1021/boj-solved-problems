#include <bits/stdc++.h>
// #define int long long
#define float long double
#define pp pair<int, int>
#define tp tuple<int, int, int>
#define mtp make_tuple
#define mp make_pair
using namespace std;
// using lf = __float128;
// using ld = __int128;
// float pi = 3.141592653589793238462643383279502884197169399375105Q;
#define INF 17'000'000
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int graph[16][16];
int dp[16][1 << 16][16];

int go(int start, int visited, int location)
{
    int &ret = dp[start][visited][location];
    if (ret)
        return ret;
    ret = INF;
    if (!((visited >> start) & 1))
        return ret = INF;
    if ((1 << location) == visited)
        return ret = 0;
    for (int i = 15; i >= 0; i--)
    {
        if (!graph[i][location])
            continue;
        if (!((visited >> i) & 1))
            continue;
        ret = min(go(start, visited - (1 << location), i) + graph[i][location], ret);
    }
    return ret;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    int output = INF;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int st = 0; st < n; st++)
        {
            if (st == i || !graph[i][st])
                continue;
            output = min(output, go(st, (1 << n) - 1, i) + graph[i][st]);
        }
    }
    cout << output;
    return 0;
}
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
#define INF 2'000'003

int isp[INF];
int visited[INF];
vector<int> ps;
vector<int> arr;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i != n - 1 && arr[i] == arr[i + 1])
            continue;
        for (int j = 0; j < n; j++)
        {
            if (j != n - 1 && arr[j] == arr[j + 1])
                continue;
            int x = arr[i] * arr[j];
            if (x > INF)
                break;
            visited[x] = 1;
        }
    }
    for (int i = 0; i <= INF; i++)
    {
        if (!visited[i])
        {
            cout << i;
            break;
        }
    }
    return 0;
}
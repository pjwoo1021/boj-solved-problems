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

float s, p;
float f(float x)
{
    return x * powl(p, (float)1 / x);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> p;

    int ret = -1;
    int pol = log(p);
    int r = pol + 5;
    if (s == p)
        ret = 1;
    else
    {
        for (int x = pol + 3; x >= 2; x--)
        {
            if (f(x) <= s)
                ret = x;
        }
    }

    cout << ret;
    return 0;
}
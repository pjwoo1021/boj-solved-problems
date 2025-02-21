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
float pi = 3.141592653589793238462643383279502884197169399375105Q;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int ddx[8] = {0, 0, 1, -1, 1, 1, -1, 1}, ddy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

array<float, 2> B;
array<float, 2> C;
array<float, 3> pqrs(array<float, 2> P)
{
    float p = sqrt(P[0] * P[0] + P[1] * P[1]);
    float q = sqrt(P[0] * P[0] + (B[1] - P[1]) * (B[1] - P[1]));
    float r = sqrt((C[0] - P[0]) * (C[0] - P[0]) + (C[1] - P[1]) * (C[1] - P[1]));
    return {p, q, r};
}
float gradx(array<float, 2> P)
{
    auto [p, q, r] = pqrs(P);
    return P[0] / p + P[0] / q + (P[0] - C[0]) / r;
}
float grady(array<float, 2> P)
{
    auto [p, q, r] = pqrs(P);
    return P[1] / p + (P[1] - B[1]) / q + (P[1] - C[1]) / r;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    array<float, 3> points[3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> points[i][j];
        }
    }
    array<float, 3> sides;
    int temp = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            float len = 0;
            for (int k = 0; k < 3; k++)
            {
                len += abs(points[i][k] - points[j][k]) * abs(points[i][k] - points[j][k]);
            }
            sides[temp++] = sqrtl(len);
        }
    }
    sort(sides.begin(), sides.end());
    auto [a, b, c] = sides;
    if (a == b && b == c)
    {
        cout << 0;
        return 0;
    }
    float theta = acosl((c * c + b * b - a * a) / (2 * c * b));

    B[0] = 0, B[1] = b;
    C[0] = c * sinl(theta), C[1] = c * cosl(theta);

    float x = (B[0] + C[0]) / 3, y = (B[1] + C[1]) / 3;
    int t = 500000;
    float wx = 1000000000, wy = 1000000000;
    float r = 0.999;
    cout.precision(20);
    while (t--)
    {
        array<float, 2> P = {x, y};
        if (isnan(gradx(P)) || isnan(grady(P)))
            break;
        x -= gradx(P) * wx;
        y -= grady(P) * wy;
        wx *= r;
        wy *= r;
    }
    {
        auto [p, q, r] = pqrs({x, y});
        cout << p + q + r;
    }
    return 0;
}
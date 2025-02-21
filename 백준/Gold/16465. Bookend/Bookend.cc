#include <bits/stdc++.h>
#define int long long
#define float long double
#define pp pair<int, int>
#define tp tuple<int, int, int>
#define mtp make_tuple
#define mp make_pair
using namespace std;
//using lf = __float128;
//using ld = __int128;
//float pi = 3.141592653589793238462643383279502884197169399375105Q;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int ddx[8] = {0, 0, 1, -1, 1, 1, -1, 1}, ddy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,l,s=0;cin>>n>>m>>l;
    int output;
    for(int i=0;i<n;i++){int x;cin>>x;s+=x;}
    if(s>m) output=-1;
    if(s==m) output=0;
    if(s<m){//책을 정상적으로 놓을 수 있는 경우
        if(l<=s) output=1;
        else if(s+l<=m) output=1;
        else output=-1;
    }
    cout<<output;
    return 0;
}
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

#define MOD 1'000'003

int fastpow(int a, int n){
    int result=1;
    while(n){
        if(n&1){
            result *=a;
            if(result>=MOD) result%=MOD;
        }
        a*=a;
        if(a>=MOD) a%=MOD;
        n>>=1;
    }
    return result;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;cin>>k;
    int output=(2*(fastpow(4, k-1)-1))%MOD;
    output=output*fastpow(3, MOD-2)%MOD;
    output-=fastpow(2, k-1);
    output=(output+3*MOD)%MOD;
    cout<<(output+1)%MOD;
    return 0;
}
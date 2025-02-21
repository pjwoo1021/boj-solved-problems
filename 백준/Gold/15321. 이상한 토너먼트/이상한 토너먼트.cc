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
#define INF 500000000
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int ddx[8] = {0, 0, 1, -1, 1, 1, -1, 1}, ddy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

int n;
int arr[555];
pp dp[555][555];
pp go(int le, int ri){
    if(le==ri){
        dp[le][ri].first=0;
        dp[le][ri].second=arr[le];
        return dp[le][ri];
    }
    if(dp[le][ri].first!=-1){
        return dp[le][ri];
    }
    dp[le][ri].first=INF;
    for(int md=le;md<ri;md++){
        pp ple=go(le, md);
        pp pri=go(md+1, ri);
        dp[le][ri].first=min(dp[le][ri].first, ple.first+pri.first+abs(ple.second-pri.second));
        dp[le][ri].second=max(ple.second, pri.second);
    }
    return dp[le][ri];
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<go(0, n-1).first;
    return 0;
}
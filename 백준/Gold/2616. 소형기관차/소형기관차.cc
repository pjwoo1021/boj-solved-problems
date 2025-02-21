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

int dp[4][505050]={0,};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> arr(505050, 0);
    vector<int> sum(505050, 0);
    for(int i=1;i<=n;i++) {cin>>arr[i];sum[i]=sum[i-1]+arr[i];}
    int l;cin>>l;
    for(int i=1;i<=n-l+1;i++){
        arr[i]=sum[i+l-1]-sum[i-1];
    }
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            if(j-l>=0) dp[i][j]=max(dp[i-1][j-l]+arr[j-l+1], dp[i][j-1]);
        }
    }
    cout<<dp[3][n];
    return 0;
}
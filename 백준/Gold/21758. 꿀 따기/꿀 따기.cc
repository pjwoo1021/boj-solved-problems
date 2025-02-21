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

    int n;cin>>n;
    vector<int> arr(n+1);
    vector<int> sum(n+1, 0);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum[i]=sum[i-1]+arr[i];
    }
    int output=0;
    for(int j=2;j<n;j++){
        output=max(output, 2*(sum[n]-sum[j])+(sum[j-1]-sum[1]));
    }
    for(int t=2;t<n;t++){
        output=max(output, sum[t]-sum[1]+sum[n-1]-sum[t-1]);
    }
    for(int j=2;j<n;j++){
        output=max(output, sum[n-1]-sum[j]+sum[j-1]*2);
    }
    cout<<output;
    return 0;
}
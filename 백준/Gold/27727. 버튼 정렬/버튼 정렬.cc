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
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int k;cin>>k;
    int idx=-1;
    for(int i=n;i>=2;i--){
        if(arr[i-1]>arr[i]){idx=i;break;}
    }
    int MAX=-1;
    for(int i=1;i<=idx;i++){
        MAX=max(MAX, arr[i]);
    }

    int ret=0;
    for(int i=1;i<=n;i++){
        if(MAX==-1 || idx==-1) break;
        if(arr[i]>MAX) {idx=i;if(k>=0&&i!=1)ret++;break;}
        k-=MAX-arr[i];
        arr[i]=MAX;
        if(i==n && k>=0) ret++;
    }
    if(k>0)
    for(int i=max(2ll, idx);i<=n;i++){
        int diff=arr[i]-arr[i-1];
        k-=(i-1)*diff;
        if(k<0) {
            k+=(i-1)*diff; 
            ret+=k/(i-1);
            k=0;
            break;
        }
        ret+=diff;
    }
    if(k>0) ret+=k/n;
    cout<<ret;
    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define float long double
#define pp pair<int, int>
#define tp tuple<int, int, int>
#define mtp make_tuple
#define mp make_pair
using namespace std;
//using lf = __float128;
using ld = __int128;
//float pi = 3.141592653589793238462643383279502884197169399375105Q;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int ddx[8] = {0, 0, 1, -1, 1, 1, -1, 1}, ddy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    vector<ld> arr(n);
    for(ld i=0;i<n;i++){
        int x;cin>>x;
        arr[i]=x;
    }
    ld left=0, right=(ld)1e18, ret;
    while(left<=right){
        ld mid=left+right>>1;
        ld counter=0;
        for(ld i=0;i<n;i++){
            counter+=mid/arr[i];
            if(counter>=(ld)m) break;
        }
        if(counter>=(ld)m){
            ret=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    cout<<(int)ret;
    return 0;
}
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
    int tmp=1, maxe;
    for(int i=1;;i++){
        tmp*=3;
        maxe=i;
        if(tmp>(int)1e18) break;
    }
    vector<int> arr;
    vector<int> d[50];
    for(int i=0;i<n;i++){
        int x;cin>>x;
        arr.push_back(x);
    }

    for(int i=0;i<n;i++){
        int x=1, e;
        for(int j=0;j<=maxe;j++){
            if(arr[i]%x) break;
            e=j;
            x*=3;
        }
        d[e].push_back(arr[i]);
    }
    for(int i=0;i<=maxe;i++){
        sort(d[i].begin(), d[i].end());
    }
    
    for(int i=maxe;i>=0;i--){
        for(auto x: d[i]) cout<<x<<' ';
    }

    return 0;
}
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

    int n,m;cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int left=0, right=10000, ret;
    while(left<=right){
        int mid=left+right>>1;
        int idx=0;
        int counter=0;
        bool flag=1;
        while(flag){
            int MIN,MAX;
            MIN=MAX=arr[idx];
            for(int j=idx;j<n;j++){
                MIN=min(MIN, arr[j]);
                MAX=max(MAX, arr[j]);
                if(MAX-MIN>mid){
                    idx=j;
                    counter++;
                    break;
                }
                if(j==n-1){
                    counter++;
                    flag=false;
                }
            }
        }

        if(counter<=m){
            ret=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    cout<<ret;
    return 0;
}
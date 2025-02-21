#include <bits/stdc++.h>
// #define int long long
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
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    long long sum=0;
    int mid=n>>1;
    for(int i=0;i<mid;i++){
        sum-=arr[i]*2;
    }sum+=arr[mid-1];
    for(int i=mid;i<n;i++){
        sum+=arr[i]*2;
    }sum-=arr[mid];
    if(n%2==0) {cout<<sum;return 0;}
    sum-=arr[mid-1];
    sum-=arr[mid+1];
    cout<<max(sum, sum+arr[mid-1]-arr[mid]*2+arr[mid+1]);
    return 0;
}
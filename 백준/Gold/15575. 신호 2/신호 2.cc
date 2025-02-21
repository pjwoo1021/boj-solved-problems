#include <bits/stdc++.h>
#define int long long
#define float long double
#define pp pair<int, int>
#define tp tuple<int, int, int>
#define mtp make_tuple
#define mp make_pair
using namespace std;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int ddx[8] = {0, 0, 1, -1, 1, 1, -1, 1}, ddy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

float dist(int x1, int x2, int y1, int y2){
    return sqrtl((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
pair<float, float> dp[2020202];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<pair<int, pp>> arr;
    vector<pp> brr(n);
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        brr[i]={x,y};   
    }
    sort(brr.begin(), brr.begin()+n);
    int idx=-1;
    for(int i=0;i<n;i++){
        auto [x,y]=brr[i];
        arr.push_back({1,{2,3}});
        arr[++idx].first=x;
        arr[idx].second.first=arr[idx].second.second=y;
        for(int j=i;j<n;j++){
            if(brr[j].first!=x) {i=j-1;break;}
            auto [nx, ny]=brr[j];
            arr[idx].second.first=max(arr[idx].second.first, ny);
            arr[idx].second.second=min(arr[idx].second.second, ny);
            if(j==n-1) {i=j;break;}
        }
    }

    for(int i=0;i<arr.size()-1;i++){
        int x=arr[i].first, nx=arr[i+1].first;
        auto [up, down]=arr[i].second;
        auto [nup, ndown]=arr[i+1].second;
        {
            dp[i+1].first=max(dp[i].first+dist(x, nx, up, nup), dp[i].second+dist(x, nx, down, nup));
        }
        {
            dp[i+1].second=max(dp[i].first+dist(x, nx, up, ndown), dp[i].second+dist(x, nx, down, ndown));
        }
    }

    cout<<fixed;
    cout.precision(6);
    cout<<max(dp[arr.size()-1].first,dp[arr.size()-1].second);
    return 0;
}
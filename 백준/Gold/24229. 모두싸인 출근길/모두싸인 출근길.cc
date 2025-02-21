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

    int output=0;
    vector<pp> arr(202020);
    vector<pp> brr;
    bool visited[202020]={0, };
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        arr[i]={x,y};
    }
    sort(arr.begin(), arr.begin()+n);
    //합쳐서 brr에 넣기
    for(int i=0;i<n;i++){
        int le=arr[i].first, ri=arr[i].second;
        for(int j=i+1;j<n;j++){
            if(le<=arr[j].first && arr[j].first<=ri) ri=max(ri, arr[j].second);
            if(j==n-1 || ri<arr[j].first) {i=j-1;break;}
        }
        brr.push_back({le, ri});
    }

    int sz=brr.size(), MAX=0;
    queue<array<int, 3>> q;
    q.push({brr[0].first, brr[0].second, 0});
    visited[0]=1;
    while(!q.empty()){
        auto [le, ri, idx]=q.front();
        q.pop();
        MAX=max(MAX, ri);
        for(int i=idx+1;i<sz;i++){
            auto [nle, nri] = brr[i];
            if(ri + (ri-le) < nle) break;
            if(visited[i]) continue;
            visited[i]=1;
            q.push({nle, nri, i});
        }
    }
    cout<<MAX;
    return 0;
}
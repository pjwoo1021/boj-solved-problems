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

bool cmp(pp p1, pp p2){
    return p1.first>p2.first;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<pp> arr(n+1);
    priority_queue<pp> pq;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        arr[i]={x,y};
    }
    sort(arr.begin(), arr.begin()+n, cmp);
    int idx=0, output=0;
    for(int time=n;time!=0;time--){
        for(int i=idx;;i++){
            if(arr[i].first>=time){
                pq.push({arr[i].second, arr[i].first});
            }
            else{
                idx=i;
                break;
            }
        }
        if(pq.empty()) continue;
        output+=pq.top().first;
        pq.pop();
    }
    cout<<output;

    return 0;
}
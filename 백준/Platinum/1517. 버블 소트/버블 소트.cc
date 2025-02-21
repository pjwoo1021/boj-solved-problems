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
#define INF 500'000
vector<int> arr(505050);
vector<int> seg;

void update(int idx, int s, int e, int v){
    if(s<=v && v<=e) seg[idx]++;
    if(v<s || e<v || s==e) return;

    int md=s+e>>1;
    update(idx*2, s, md, v), update(idx*2+1, md+1, e, v);
}

int count(int idx, int s, int e, int v){
    if(e<v) return seg[idx];
    if(s==e) return 0;
    if(v<=s) return 0;
    int md=s+e>>1;
    return count(idx*2, s, md, v)+count(idx*2+1, md+1, e, v);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    int h=(int)ceil(log2(INF));h++;
    seg.assign(1<<h, 0);

    set<pp> st;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        st.insert({arr[i], i});
    }
    int cnt=1;
    for(auto i=st.begin();i!=st.end();i++){
        int idx=i->second;
        arr[idx]=cnt++;
    }

    int output=0;
    for(int i=n;i>=1;i--){
        output+=count(1, 1, INF, arr[i]);
        update(1, 1, INF, arr[i]);
    }
    cout<<output;
    return 0;
}
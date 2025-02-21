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
#define MOD 1'000'000'007


vector<int> seg;
vector<int> arr(1010101);

int make_seg(int idx, int s, int e){
    if(s==e) return seg[idx]=arr[s]%MOD;
    int md=s+e>>1;
    return seg[idx]=make_seg(idx*2, s, md) * make_seg(idx*2+1, md+1, e) % MOD;
}

int query(int idx, int s, int e, int le, int ri){
    if(le<=s && e<=ri) return seg[idx];
    if(ri<s || e<le) return 1;
    int md=s+e>>1;
    return query(idx*2, s, md, le, ri) * query(idx*2+1, md+1, e, le, ri) % MOD;
}

int update(int idx, int s, int e, int v, int x){
    // if(s<=v && v<=e) {seg[idx]/=arr[v];seg[idx]=seg[idx]*(arr[v]+dx)%MOD;}
    if(v<s || e<v) return seg[idx];
    if(s==e) return seg[idx]=x;
    
    int md=s+e>>1;
    return seg[idx]=update(idx*2, s, md, v, x)*update(idx*2+1, md+1, e, v, x)%MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int h=(int)ceil(log2(n));
    h++;
    seg.resize(1<<h);
    
    make_seg(1, 1, n);

    for(int i=0;i<m+k;i++){
        int q;cin>>q;
        if(q==1){
            int v, x;cin>>v>>x;
            update(1, 1, n, v, x);   
            arr[v]=x;
        }
        if(q==2){
            int le, ri;cin>>le>>ri;
            cout<<query(1, 1, n, le, ri)<<'\n';
        }
    }
    return 0;
}
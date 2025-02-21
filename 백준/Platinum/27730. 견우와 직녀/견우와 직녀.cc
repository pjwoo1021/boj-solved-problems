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
int n, m;

int make_tree(int location, int mom, vector<pp> arr[], vector<pp> next[], int cnt[]){
    cnt[location]=1;
    for(auto x: arr[location]){
        if(x.first==mom) continue;
        next[location].push_back(x);
        cnt[location]+=make_tree(x.first, location, arr, next, cnt);
    }
    return cnt[location];
}

void go(int location, int n, int sum[], vector<pp> next[], int cnt[]){
    for(auto p:next[location]){
        auto [x, c]=p;
        sum[x]=sum[location]+(c * (n-2*cnt[x]));
        go(x, n, sum, next, cnt);
    }
}

int upgo(int location, vector<pp> next[], int cnt[], int updp[]){
    if(updp[location]!=-1) return updp[location];
    int ret=0;
    for(auto p:next[location]){
        auto [x, c]=p;
        ret+=upgo(x, next, cnt, updp);
        ret+=c*cnt[x];
    }
    return updp[location]=ret;
}

int acnt[101010]={0,}, bcnt[101010]={0,}, aupdp[101010], bupdp[101010];
vector<pp> anext[101010], bnext[101010];
int asum[101010]={0,}, bsum[101010]={0,};
vector<pp> arr[101010], brr[101010];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0;i<n-1;i++){
        int s,e,x;cin>>s>>e>>x;
        arr[s].push_back({e, x});
        arr[e].push_back({s, x});
    }
    cin>>m;
    for(int i=0;i<m-1;i++){
        int s,e,x;cin>>s>>e>>x;
        brr[s].push_back({e, x});
        brr[e].push_back({s, x});
    }

    memset(aupdp, -1, sizeof(aupdp));
    memset(bupdp, -1, sizeof(bupdp));
    make_tree(1, 0, arr, anext, acnt);
    make_tree(1, 0, brr, bnext, bcnt);

    asum[1]=upgo(1, anext, acnt, aupdp);
    bsum[1]=upgo(1, bnext, bcnt, bupdp);

    go(1, n, asum, anext, acnt);
    go(1, m, bsum, bnext, bcnt);

    int MIN=(int)1e15, u, v;
    for(int i=1;i<=n;i++){
        MIN=min(MIN, asum[i]);
    }
    for(int i=1;i<=n;i++){
        if(asum[i]==MIN) {u=i;break;}
    }
    MIN=(int)1e15;
    for(int i=1;i<=m;i++){
        MIN=min(MIN, bsum[i]);
    }
    for(int i=1;i<=m;i++){
        if(bsum[i]==MIN) {v=i;break;}
    }

    cout<<u<<' '<<v<<'\n';
    cout<<(asum[u]*m+n*bsum[v]+(n*m));
    return 0;
}
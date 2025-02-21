#include <bits/stdc++.h>
#define int long long
#define float long double
#define pp pair<int, int>
#define tp tuple<int, int, int>
#define mtp make_tuple
#define mp make_pair
using namespace std;
#define MAX 1'000'000'000
#define MIN 1
//using lf = __float128;
//using ld = __int128;
//float pi = 3.141592653589793238462643383279502884197169399375105Q;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int ddx[8] = {0, 0, 1, -1, 1, 1, -1, 1}, ddy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

vector<int> arr(101010);
vector<int> segm;
vector<int> segM;
int make_tree(int idx, int st, int ed){
    if(st==ed) return segm[idx]=arr[st];
    int md=st+ed>>1;
    return segm[idx]=min(make_tree(idx*2, st, md), make_tree(idx*2+1, md+1, ed));
}

int Make_tree(int idx, int st, int ed){
    if(st==ed) return segM[idx]=arr[st];
    int md=st+ed>>1;
    return segM[idx]=max(Make_tree(idx*2, st, md), Make_tree(idx*2+1, md+1, ed));
}

pp q(int idx, int st, int ed, int le, int ri){
    pp p;
    if(le<=st && ed<=ri){
        p.first=segm[idx];
        p.second=segM[idx];
        return p;
    }
    if(ri<st) return {MAX, MIN};
    if(ed<le) return {MAX, MIN};

    int md=st+ed>>1;
    pp l=q(idx*2, st, md, le, ri), r=q(idx*2+1, md+1, ed, le, ri);
    p.first=min(l.first, r.first);
    p.second=max(l.second, r.second);
    return p;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    int h=(int)ceil(log2(n));
    segm.resize(1<<(h+1));
    segM.resize(1<<(h+1));
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    make_tree(1, 1, n);
    Make_tree(1, 1, n);
    
    for(int i=0;i<m;i++){
        int le, ri;cin>>le>>ri;
        pp p=q(1, 1, n, le, ri);
        cout<<p.first<<' '<<p.second<<'\n';
    }
    return 0;
}
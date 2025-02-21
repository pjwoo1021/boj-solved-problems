// #include <bits/stdc++.h>
// #define int long long
// #define float long double
// #define pp pair<int, int>
// #define tp tuple<int, int, int>
// #define mtp make_tuple
// #define mp make_pair
// using namespace std;
// using lf = __float128;
// using ld = __int128;
// float pi = 3.141592653589793238462643383279502884197169399375105Q;
// int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

// int segmake(vector<int> &arr, vector<int> &segtree, int node, int start, int end) {
//     // segmake(arr, segtree, 1, 0, n-1);
//     if (start == end)
//         return segtree[node] = arr[start];
//     int mid = start + end >> 1;

//     // 구간 합을 구하는 경우
//     return segtree[node] = segmake(arr, segtree, node * 2, start, mid) + segmake(arr, segtree, node * 2 + 1, mid + 1, end);
//     // 구간의 최솟값을 구하는 경우도 비슷하게 해줄 수 있다.
//     // return segtree[node] = min(segmake(arr, segtree, node * 2, start, mid), segmake(arr, segtree, node * 2 + 1, mid + 1, end));
// }

// int segsum(vector<int> &segtree, int node, int start, int end, int left, int right) {
//     if (right < start || end < left)
//         return 0;
//     if (left <= start && end <= right)
//         return segtree[node];
//     int mid = start + end >> 1;
//     return segsum(segtree, node * 2, start, mid, left, right) + segsum(segtree, node * 2 + 1, mid + 1, end, left, right);
// }

// void segupdate(vector<int> &segtree, int node, int start, int end, int index, int diff) {
//     if (index < start || end < index)
//         return;
//     segtree[node] = segtree[node] + diff;
//     if (start != end) {
//         int mid = start + end >> 1;
//         segupdate(segtree, node * 2, start, mid, index, diff);
//         segupdate(segtree, node * 2 + 1, mid + 1, end, index, diff);
//     }
// }

// signed main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(nullptr);

//     int n, m, k;
//     cin >> n >> m >> k;

//     int segh = (int)ceil(log2(n));
//     vector<int> segtree(1 << (segh + 1));
//     vector<int> arr(n + 1);
//     for (int i = 1; i <= n; i++) {
//         cin >> arr[i];
//     }
//     segmake(arr, segtree, 1, 1, n);
//     for (int i = 0; i < m + k; i++) {
//         int a, b, c;
//         cin >> a >> b >> c;
//         if (a == 1) {
//             segupdate(segtree, 1, 1, n, b, c - arr[b]);
//             arr[b] = c;
//         } else {
//             cout << segsum(segtree, 1, 1, n, b, c) << '\n';
//         }
//     }
//     return 0;
// }


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
// int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
// int ddx[8] = {0, 0, 1, -1, 1, 1, -1, 1}, ddy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
vector<int> arr(1010101);
vector<int> seg;

int make_tree(int idx, int s, int e){
    if(s==e){
        return seg[idx]=arr[s];
    }
    int md=s+e>>1;
    return seg[idx]=make_tree(idx*2, s, md)+make_tree(idx*2+1, md+1, e);
}

int query(int idx, int s, int e, int le, int ri){
    if(e<le) return 0;
    if(ri<s) return 0;
    if(le<=s && e<=ri){
        return seg[idx];
    }
    int md=s+e>>1;
    return query(idx*2, s, md, le, ri)+query(idx*2+1, md+1, e, le, ri);
}

void update(int idx, int s, int e, int v, int dx){
    if(s<=v && v<=e) seg[idx]+=dx;
    if(v<s || e<v) return;
    if(s==e) return;
    
    int md=s+e>>1;
    update(idx*2, s, md, v, dx);
    update(idx*2+1, md+1, e, v, dx);
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    int m,k;cin>>m>>k;
    int h=(int)ceil(log2(n));
    seg.resize(1<<(h+1), 0);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    make_tree(1, 1, n);
    for(int i=0;i<m+k;i++){
        int q;cin>>q;
        if(q==1){
            int v, x;cin>>v>>x;
            int dx=x-arr[v];
            arr[v]=x;
            update(1, 1, n, v, dx);
        }
        if(q==2){
            int le,ri;cin>>le>>ri;
            cout<<query(1, 1, n, le, ri)<<'\n';
        }
    }
    return 0;
}
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
int ddx[8] = {0, 0, 1, -1, 1, 1, -1, 1}, ddy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

int n,h;
vector<int> arr(262'143+1);
void make_graph(vector<vector<pp>> &graph, int x, int y, int location){
    graph[y].push_back({x, arr[location]});
    int dx=pow(2, h-y-2);
    int x1=x-dx, x2=x+dx, ny=y+1;
    if(0<=x1&&x1<n && 1<=location*2&&2*location<=n)
        make_graph(graph, x1, ny, location*2);
    if(0<=x2&&x2<n && 1<=(location*2+1)&&(2*location+1)<=n)
        make_graph(graph, x2, ny, location*2+1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    h=(int)log2(n+1);
    vector<vector<pp>> graph(h);

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    make_graph(graph, n-1>>1, 0, 1);

    int output=arr[1];
    for(int up=0;up<h;up++){
        for(int down=up;down<h;down++){
            vector<pp> subarr;
            for(int h=up;h<=down;h++){
                for(auto x:graph[h]) subarr.push_back(x);
            }
            sort(subarr.begin(), subarr.end());
            vector<int> dp;
            int MAX=subarr[0].second;
            for(auto x:subarr){
                if(dp.empty()) dp.push_back(x.second);
                else{
                    dp.push_back(max(x.second, x.second+dp.back()));
                }
                MAX=max(MAX, dp.back());
            }
            output=max(MAX, output);
        }
    }
    cout<<output;

    return 0;
}
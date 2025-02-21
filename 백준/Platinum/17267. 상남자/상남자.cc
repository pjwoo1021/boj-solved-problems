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
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

bool visited[1010][1010];
vector<vector<int>> world(1010, vector<int>(1010, 1));

int counter=0;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;cin>>n>>m;
    int l,r;cin>>l>>r;
    pp slocation;
    for(int i=0;i<n;i++){
        string str;cin>>str;
        for(int j=0;j<m;j++){
            world[i+1][j+1]=str[j]-'0';
            if(str[j]=='2'){
                slocation={i+1,j+1};
                visited[i+1][j+1]=1;
            }
        }
    }
    deque<pair<pp,pp>> dq;
    dq.push_back({slocation,{l,r}});
    while(!dq.empty()){
        auto [p1,p2]=dq.front();
        auto [x,y]=p1;
        auto [left,right]=p2;
        dq.pop_front();

        bool flag=0;
        for(int i=0;i<2;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(visited[nx][ny]) continue;
            if(world[nx][ny]==1) continue;
            dq.push_front({{nx,ny},{left,right}});
            visited[nx][ny]=1;
            flag=1;
        }
        if(flag){dq.push_back({{x,y},{left,right}});continue;}
        for(int i=2;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(visited[nx][ny]) continue;
            if(world[nx][ny]==1) continue;
            if(i==2&&right>=1) {dq.push_back({{nx,ny},{left,right-1}});visited[nx][ny]=1;}
            if(i==3&&left>=1) {dq.push_back({{nx,ny},{left-1,right}});visited[nx][ny]=1;}
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            counter+=visited[i][j];
        }
        // cout<<'\n';
    }
    cout<<counter;
    return 0;
}
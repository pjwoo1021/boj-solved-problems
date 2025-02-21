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
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int ddx[8] = {0, 0, 1, -1, 1, 1, -1, 1}, ddy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

int r,c,k;
vector<vector<char>> world(155, vector<char>(150, 'x'));
string s={'R', 'D', 'L', 'U'};
        // idx  i   idx인데 i로 회전하고 싶으면 오른쪽으로 한번 회전하면 된다. i-idx이다.
int cor(int x, int y, int i){
    int idx=0;
    for(int j=0;j<4;j++){
        if(world[x][y]!=s[j]) continue;
        idx=j;break;
    }
    //현재 world는 idx위치를 가리키고 있다.
    if(i<idx) return i+4-idx;
    return i-idx;
}
int col(int x, int y, int i){
    int idx=0;
    for(int j=0;j<4;j++){
        if(world[x][y]!=s[j]) continue;
        idx=j;break;
    }
    //현재 world는 idx위치를 가리키고 있다.
    if(idx<i) return idx+4-i;
    return idx-i;
}

bool visited[55][55][150][150]={0,};
int go(int x, int y, int p, int q){
    int output=0;
    if(p>k || q>k) return 0;
    if(x==r && y==c) return 1;

    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(world[nx][ny]=='x') continue;
        int cl=col(x, y, i)%4;
        int cr=cor(x, y, i)%4;

        if(visited[nx][ny][p+cl][q]==0){
            visited[nx][ny][p+cl][q]=1;
            output=max(output, go(nx, ny, p+cl, q));
        }

        if(visited[nx][ny][p][q+cr]==0){
            visited[nx][ny][p][q+cr]=1;
            output=max(output, go(nx, ny, p, q+cr));
        }
    }

    return output;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>r>>c>>k;
    for(int i=1;i<=r;i++){
        string str;cin>>str;
        for(int j=1;j<=c;j++){
            world[i][j]=str[j-1];
        }
    }

    cout<<((go(1, 1, 0, 0)) ? "Yes" : "No")<<'\n';
    return 0;
}
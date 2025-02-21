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

int n,m,k;
vector<vector<char>> world(155, vector<char>(155, 'x'));
string s={'R', 'D', 'L', 'U'};

int costl[4][4];
int costr[4][4];
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

int d[155][155][1555];

int de(char x){
    if(x=='R') return 0;
    if(x=='D') return 1;
    if(x=='L') return 2;
    if(x=='U') return 3;
}

void dijk(){
    priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> pq;
    pq.push({0,0,1,1});
    d[1][1][0]=0;
    while(!pq.empty()){
        auto [r,l,x,y]=pq.top();//x y주문서 l만큼 썼을 때 가장 작은 r을 들고 다녀야 할 것 같지 않음?
        if(x==n&&y==m) return;
        pq.pop();
        if(d[x][y][l]!=r) continue;

        for(int i=0;i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(world[nx][ny]=='x') continue;
            int cl=l+costl[de(world[x][y])][i];
            int cr=r+costr[de(world[x][y])][i];

    
            if(cl<=k && r<d[nx][ny][cl]){
                d[nx][ny][cl]=r;
                pq.push({r, cl, nx, ny});
            }
            if(cr<d[nx][ny][l] && cr<=k){
                d[nx][ny][l]=cr;
                pq.push({cr, l, nx, ny});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        string str;cin>>str;
        for(int j=1;j<=m;j++){
            world[i][j]=str[j-1];
        }
    }
    memset(d,(int)0x3f3f3f3f3f3f3f3fLL, sizeof(d));
    for(int i=0;i<4;i++){
        //화살표의 위치 i
        world[153][153]=s[i];
        for(int j=0;j<4;j++){
            //dx dy의 방향 j
            costr[i][j]=cor(153, 153, j);
            costl[i][j]=col(153, 153, j);
        }
    }

    dijk();
    for(int i=0;i<=k;i++){
        if(d[n][m][i]!=(int)0x3f3f3f3f3f3f3f3fLL){cout<<"Yes";return 0;}
    }
    cout<<"No";
    return 0;
}
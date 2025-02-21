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

int bin_search(int n, int k){
    int le=-1, ri=1e9, ret;
    while(le<=ri){
        int md=le+ri>>1;
        int base;
        if(n%2==0) base=n*n*md+n*n/2;
        else{
            int x=md*2;
            if(k%2==0) base=n*n*x+n*n/2;
            if(k%2) base=n*n*x+n*n/2+1;
        }
        if(base<=k){
            ret=(n%2 ? md*2 : md);
            le=md+1;
        }
        else ri=md-1;
    }
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;cin>>n>>k;
    vector<vector<int>> output(1010, vector<int>(1010,0));

    if(n%2==0 && k%2==1){cout<<-1;return 0;}
    int x=bin_search(n, k);
    if(x<0) {cout<<-1;return 0;}
    if(n%2==0 || k%2==0){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                output[i][j]=x+(i+j)%2;
                k-=output[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(k==0) {i=n;break;}
                if((i+j)%2) continue;
                output[i][j]+=2;
                k-=2;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(k==0) {i=n;break;}
                if((i+j+1)%2) continue;
                output[i][j]+=2;
                k-=2;
            }
        }
    }
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                output[i][j]=x+(i+j+1)%2;
                k-=output[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(k==0) {i=n;break;}
                if((i+j+1)%2) continue;
                output[i][j]+=2;
                k-=2;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(k==0) {i=n;break;}
                if((i+j)%2) continue;
                output[i][j]+=2;
                k-=2;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<output[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
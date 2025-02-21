#include <bits/stdc++.h>
#define int long long
#define float long double
#define pp pair<int, int>
#define tp tuple<int, int, int>
#define mtp make_tuple
#define mp make_pair
using namespace std;
using lf = __float128;
using ld = __int128;
float pi = 3.141592653589793238462643383279502884197169399375105Q;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int ddx[8] = {0, 0, 1, -1, 1, 1, -1, 1}, ddy[8] = {1, -1, 0, 0, 1, -1, 1, -1};


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A,B,C,D,E,F,G,H;cin>>A>>B>>C>>D>>E>>F>>G>>H;
    int counter=0;
    bool visited[14]={0,};
    for(int l=1;l<=13;l++){
        visited[l]=1;

        int m=H-l;
        if(m<=0 || visited[m]) {visited[l]=0;continue;}
        visited[m]=1;
        
    for(int d=1;d<=13;d++){
        if(visited[d]) continue;
        visited[d]=1;

        int h=D-d;
        if(h<=0 || visited[h]) {visited[d]=0;continue;}
        visited[h]=1;
    for(int i=1;i<=13;i++){
        if(visited[i]) continue;
        visited[i]=1;

    for(int j=1;j<=13;j++){
        if(visited[j]) continue;
        visited[j]=1;
        int k=G-i-j;
        if(k<=0 || visited[k]) {visited[j]=0;continue;}
        visited[k]=1;

    for(int a=1;a<=13;a++){
        if(visited[a]) continue;
        visited[a]=1;

        int e=A-a-i-l;
        if(e<=0 || visited[e]) {visited[a]=0;continue;}
        visited[e]=1;

    for(int f=1;f<=13;f++){
        if(visited[f]) continue;
        visited[f]=1;

        int g=F-e-f-h;
        if(g<=0 || visited[g]) {visited[f]=0;continue;}
        visited[g]=1;

    for(int b=1;b<=13;b++){
        if(visited[b]) continue;
        visited[b]=1;

        int c=E-a-b-d;
        if(c<=0 || visited[c]||(B!=b+f+j+m)||(C!=c+g+k)) {visited[b]=0;continue;}
        visited[c]=1;

        counter++;

        visited[c]=0;
        visited[b]=0;   
    }
    visited[g]=0;
    visited[f]=0;
    }
    visited[a]=0;
    visited[e]=0;
    }
    visited[k]=0;
    visited[j]=0;
    }
    visited[i]=0;
    }
    visited[d]=0;
    visited[h]=0;
    }
    visited[l]=0;
    visited[m]=0;
    }
    cout<<counter;
    return 0;
}
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

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1){
        int n;cin>>n;
        if(!n) break;
        vector<int> arr(n+1);
        vector<vector<int>> gcds(n+1, vector<int>(101, 0));
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            gcds[i][arr[i]]=1;
        }
        for(int i=1;i<=n;i++){
            for(int k=1;k<=100;k++){
                if(gcds[i-1][k]){
                    gcds[i][gcd(k, arr[i])]=1;
                }
            }
        }

        int counter=0;
        bool visited[101]={0,};
        for(int i=1;i<=n;i++){
            for(int j=1;j<=100;j++){
                if(gcds[i][j])
                    visited[j]=1;
            }
        }
        for(int i=1;i<=100;i++){
            counter+=visited[i];
        }
        cout<<counter<<'\n';
    }
    
    return 0;
}
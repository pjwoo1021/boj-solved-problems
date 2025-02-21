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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s1,s2;cin>>s1>>s2;
    int flag=0;
    for(int i=0;i<s1;i++){
        int x,y;cin>>x>>y;
        if(x!=y) flag=1;
    }
    
    for(int i=0;i<s2;i++){
        int x,y;cin>>x>>y;
        if(flag==0 && x!=y) flag=2;
    }
    if(flag==0) cout<<"Accepted";
    if(flag==1) cout<<"Wrong Answer";
    if(flag==2) cout<<"Why Wrong!!!";

    return 0;
}
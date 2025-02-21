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

    int g;cin>>g;
    int le=1,ri=2;
    bool flag=1;
    while(le<ri){
        int diff=ri*ri-le*le;
        if(diff==g) {cout<<ri++<<'\n';flag=0;}
        if(diff<g){
            ri++;
        }
        if(diff>g){
            le++;

        }
    }

    if(flag) cout<<-1;
    return 0;
}
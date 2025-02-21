#include <iostream>
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

#define MOD 1000000007
#define MAX 4000000
int fact[MAX+1];

int fastpow(int a, int n){
    int result=1;
    while(n){
        if(n&1){
            result=result*a%MOD;
        }
        a=a*a%MOD;
        n>>=1;
    }
    return result;
}

void make_fact(){
    fact[0]=1;
    for(int sz=1;sz<=MAX;sz++){
        fact[sz]=fact[sz-1]*sz%MOD;
    }
}

int combination(int n, int k){
    if(k<0 || n<k){
        return 0;
    }
    return (fact[n]*(fastpow(fact[n-k]*fact[k]%MOD, MOD-2)))%MOD;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    make_fact();
    int t;cin>>t;
    while(t--){
        int n,r;cin>>n>>r;
        cout<<combination(n,r)<<'\n';
    }
    return 0;
}
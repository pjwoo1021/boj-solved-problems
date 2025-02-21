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

int n,m,k;

#define MOD 1'000'000'007
#define MAX 2'000'002
int fact[MAX+1];
int inv_fact[MAX+1];

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
    inv_fact[MAX]=fastpow(fact[MAX], MOD-2);
    for(int i=MAX;i!=0;i--){
        inv_fact[i-1]=inv_fact[i]*i%MOD;
    }
}

int combination(int n, int k){
    if(k<0 || n<k){
        return 0;
    }
    return (fact[n]*(inv_fact[n-k]*inv_fact[k]%MOD))%MOD;
}

vector<int> graph[21];
int output=0;
vector<pp> bombs;
void go(int mom, int counter, int ret){
    for(auto location:graph[mom]){
        int x=bombs[location].first-bombs[mom].first;
        int y=bombs[location].second-bombs[mom].second;
        go(location, counter+1, ret*combination(x+y,y)%MOD);
    }
    ret=ret*combination(n+m-bombs[mom].first-bombs[mom].second, m-bombs[mom].second)%MOD;
    if(counter%2==1) output=(output-ret+MOD+MOD)%MOD;
    if(counter%2==0) output=(output+ret)%MOD;
}



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    make_fact();
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        int x,y;cin>>x>>y;
        bombs.push_back({x,y});
        graph[k].push_back(i);
    }

    sort(bombs.begin(), bombs.end());
    
    for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            if(bombs[i].first<=bombs[j].first && bombs[i].second<=bombs[j].second){
                graph[i].push_back(j);
            }
        }
    }

    bombs.push_back({0,0});
    if(k==0) {cout<<combination(n+m,m);return 0;}
    go(k, 0, 1);
    cout<<output<<'\n';
    return 0;
}
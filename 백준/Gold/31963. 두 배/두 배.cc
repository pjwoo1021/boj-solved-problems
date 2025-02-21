#include <bits/stdc++.h>
#define int long long
using namespace std;

int fastpow(int a, int n){
    int result=1;
    while(n){
        if(n&1){
            result *=a;
        }
        a*=a;
        n>>=1;
    }
    return result;
}

vector<int> c(252525, 0);
int bin_search(int x1, int x2, int idx){
    int left=0, right=20;
    int e1=c[idx-1], e2=c[idx];
    int ret=0;
    while(left<=right){
        int mid=left+right>>1;
        int e=(e2+mid)-e1;
        bool flag=0;
        if(e>=0){
            if(x1<=x2*fastpow(2, e)){
                flag=true;
            }
        }
        if(e<0){
            if(x1*fastpow(2, -e)<=x2){
                flag=true;
            }
        }
        if(flag){
            ret=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return ret;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }

    int output=0;
    for(int i=2;i<=n;i++){
        c[i]=bin_search(arr[i-1], arr[i], i);
        output+=c[i];
    }
    cout<<output;
    return 0;
}
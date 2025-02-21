#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> arr(202020), brr(202020);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cin>>brr[i];
    }
    int left=1, right=(int)1e9, ret;
    while(left<=right){
        int mid=left+right>>1;
        vector<int> winter(202020);
        for(int i=0;i<n;i++) winter[i]=arr[i];
        for(int i=0;i<n;i++){
            winter[i]-=min(brr[i]*mid, arr[i]);
        }
        int counter=mid;
        for(int i=0;i<n;i++){
            if(!winter[i]) continue;
            counter-=(winter[i]-1)/brr[i]+1;
        }
        if(counter<0){
            left=mid+1;
        }
        else{
            ret=mid;
            right=mid-1;
        }
    }
    cout<<ret;
    return 0;
}
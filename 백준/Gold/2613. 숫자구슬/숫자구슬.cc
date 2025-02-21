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

    int n,m;cin>>n>>m;
    vector<int> arr(333);
    int le=0, ri=30'000, ret;
    //연속된 길이의 최댓값으로 이분탐색
    //md==연속된 길이의 최댓값.
    //그룹을 너무 많이 만들어야 하면(작으면) le=md+1;
    int c;
    for(int i=1;i<=n;i++) {cin>>arr[i];le=max(le, arr[i]);}
    while(le<=ri){
        int md=le+ri>>1;
        int idx=1;
        bool flag=1;
        int counter=0;
        while(flag){
            int sum=0;
            for(int i=idx;i<=n;i++){
                sum+=arr[i];
                if(sum>md){//i를 넣을 수 없는 경우
                    sum-=arr[i];
                    idx=i;
                    counter++;
                    break;
                }
                if(i==n) {flag=0;counter++;}
            }
        }
        if(counter<=m){
            ret=md;
            c=counter;
            ri=md-1;
        }
        else{
            le=md+1;
        }
   }


    cout<<ret<<'\n';
    vector<int> output;
    int idx=1;
    bool flag=1;
    //최댓값을 5로 잡았을 때 겨우겨우 m개의 그룹으로 만들 수 있는 경우
    //최댓값을 잡았는데 미친 개 널널하게 남는 경우
    //그리디하게 가장 앞에서부터 묶는 것이 그룹은 가장 적게 나오지만, 더 널널하게 그룹을 만들어야 한다.
    //그런 경우가 몇 개가 있을까

    //최댓값이 10이면 그룹이 5개, 11이면 그룹이 3개인데 m=4면 11로 해놓고 4개의 그룹을 만들면 된다.
    int i_max=-1;
    while(flag){
        int sum=0;
        int counter=0;
        for(int i=idx;i<=n;i++){
            sum+=arr[i];
            counter++;
            if(sum>ret){//i를 넣을 수 없는 경우
                counter--;
                output.push_back(counter);
                sum-=arr[i];
                idx=i;
                if(sum==ret) i_max=output.size()-1;//가장 큰 합이 담긴 output에서의 위치
                break;
            }
            if(i==n) {flag=0;output.push_back(counter);}
        }
    }
    if(output.size()==m)
        for(auto x:output) cout<<x<<' ';
    else{
        vector<int> noutput;int counter=0;
        for(int i=0;i<output.size();i++){
            if(i==i_max) {noutput.push_back(output[i]);continue;}
            
            while(output[i]>=2 && m>(output.size()+counter)){
                noutput.push_back(1);counter++;
                output[i]--;
            }
            noutput.push_back(output[i]);
        }
        for(auto x:noutput) cout<<x<<' ';
    }

    return 0;
}
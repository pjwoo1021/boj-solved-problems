#include <bits/stdc++.h>

using namespace std;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, T;
    int start=0;
    cin>>N>>T;
    vector<int> apart(2*N);
    vector<int> call(T);

    for(int i=0; i<2*N; i++){
        cin>>apart[i];
    }
    for(int i=0; i<T; i++){
        cin>>call[i];
        call[i]%=2*N;
    }
    
    for(int i=0;i<T;i++){
        start=start + (call[i]+2*N-1);
        start%=2*N;
        cout<<apart[start]<<' ';
    }

    return 0;
}
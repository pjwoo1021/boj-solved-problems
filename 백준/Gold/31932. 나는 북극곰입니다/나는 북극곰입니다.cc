#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <cmath>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define w(t) while(t--)
#define f(i, n) for(int i = 0; i < n; i++)
#define f1(i, n) for(int i = 1; i <= n; i++)

int n, m;
vector<vector<array<int, 3>>> graph(100001);


int dijk(int t) {
    vector<int> visited(n + 1, 1e10);
    priority_queue<pii> pq;
    pq.push({ -t, 1 });
    visited[1] = t;

    while (pq.size()) {
        int time = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(visited[now]!=time) continue;
        if (now == n) {
            return 1;
        }

        f(i, graph[now].size()) {
            int nxt = graph[now][i][0];
            int weight = time + graph[now][i][1];
            if (visited[nxt] > weight && weight <= graph[now][i][2])
            {
                pq.push({ -(time + graph[now][i][1]), nxt });
                visited[nxt] = weight;
            }
        }
    }

    return -1;
}

signed main() {
    fastio;

    cin >> n >> m;

    f(i, m) {
        int u, v, d, w;
        cin >> u >> v >> d >> w;
        graph[u].push_back({ v, d, w });
        graph[v].push_back({ u, d, w });
    }

    int s = 0, e = 1e10;
    int mid = -1;
    int tmp = -1;

    while (s <= e) {
        int mid = s + e>>1;
        int chk = dijk(mid);
        if (chk == -1) {
            e = mid - 1;
        }
        else if (chk == 1) {
            tmp = mid;
            s = mid + 1;
        }
    }

    cout << tmp;
    return 0;
}
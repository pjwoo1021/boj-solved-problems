#include <bits/stdc++.h>
#define int long long
#define float long double
#define pp pair<int, int>
#define tp tuple<int, int, int>
#define mtp make_tuple
#define mp make_pair
using namespace std;

int n, s, q;
vector<int> arr;
vector<int> seg;
set<int> solve[500001];

// 세그먼트 트리 초기화
void build_tree(int size) {
    for (int i = size - 1; i > 0; --i)
        seg[i] = seg[i << 1] + seg[i << 1 | 1];
}

// 업데이트 함수 (비재귀)
void update(int pos, int value, int size) {
    pos += size; // 리프 노드의 인덱스
    seg[pos] += value; // 값 갱신
    while (pos > 1) { // 부모 노드를 갱신
        pos >>= 1; // 부모로 이동
        seg[pos] = seg[pos << 1] + seg[pos << 1 | 1]; // 두 자식의 합
    }
}

// 쿼리 함수 (비재귀, [l, r] 구간 합)
int query(int l, int r, int size) {
    int result = 0;
    l += size, r += size + 1; // 리프 노드로 이동 (r 포함 처리)
    while (l < r) {
        if (l & 1) result += seg[l++]; // l이 홀수면 현재 구간 포함
        if (r & 1) result += seg[--r]; // r이 홀수면 현재 구간 포함
        l >>= 1, r >>= 1; // 부모로 이동
    }
    return result;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    cin >> q;

    int size = 1;
    while (size < q + 1) size <<= 1; // 트리의 크기 계산 (2^k 이상)

    arr.resize(n + 1, 0);
    seg.resize(size * 2, 0); // 2배 크기로 저장 (리프 + 내부 노드)

    int ra = n;
    for (int i = 2; i <= n; i++) solve[0].insert(i);

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x == 1)
            ra = query(arr[1] + 1, size, size) + 1;

        if (x != 1 && arr[x] + 1 > arr[1]) {
            if (solve[arr[x]].count(x)) {
                solve[arr[x]].erase(x);
                solve[arr[x] + 1].insert(x);
            } else {
                ra++;
                solve[arr[x] + 1].insert(x);
            }
        }

        arr[x]++;
        update(arr[x], 1, size); // 현재 레벨 증가
        update(arr[x] - 1, -1, size); // 이전 레벨 제거

        if (ra <= s) {
            cout << ra << ' ' << 0 << '\n';
            continue;
        }

        int l = 1, r = q+1, ret = 0;
        while (l <= r) {
            int m = (l + r) >> 1;
            int rank = query(m, size, size) + 1; // m 이상 구간 합
            if (rank <= s) {
                ret = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        cout << ra << ' ' << ret - arr[1] << '\n';
    }

    return 0;
}

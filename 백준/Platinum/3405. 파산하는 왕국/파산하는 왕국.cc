// CERC 2012
// Problem A: Kingdoms
// O(n^2*2^n) solution
// Author: Bartosz Walczak

#include <iostream>
#include <vector>
using namespace std;

void testcase() {
    size_t n;
    cin >> n;
    vector<vector<int> > debt(n);
    for (size_t i = 0; i < n; ++i) {
        debt[i].resize(n);
        for (size_t j = 0; j < n; ++j)
            cin >> debt[i][j];
    }
    vector<bool> reached(1U<<n, false);
    reached[(1U<<n)-1] = true;
    for (unsigned mask = (1U<<n)-1; mask; --mask)
        if (reached[mask])
            for (size_t i = 0; i < n; ++i)
                if (mask & 1U<<i) {
                    int total_debt = 0;
                    for (size_t j = 0; j < n; ++j)
                        if (mask & 1U<<j)
                            total_debt += debt[i][j];
                    if (total_debt > 0)
                        reached[mask & ~(1U<<i)] = true;
                }
    bool found = false;
    for (size_t i = 0; i < n; ++i)
        if (reached[1U<<i]) {
            if (found) cout << " ";
            cout << i+1;
            found = true;
        }
    if (!found) cout << "0";
    cout << endl;
}

int main() {
    size_t t;
    for (cin >> t; t; --t) testcase();
    return 0;
}

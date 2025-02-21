#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

typedef vector<vector<long long>> Matrix;

// 행렬 곱셈 함수
Matrix square_matrix(const Matrix &matrix1, const Matrix &matrix2) {
    Matrix result(2, vector<long long>(2, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                result[i][j] = (MOD+result[i][j] + (matrix1[i][k] % MOD) * (matrix2[k][j] % MOD) % MOD) % MOD;
            }
        }
    }
    return result;
}

// 행렬 제곱을 구하는 함수 (분할 정복 방식)
Matrix solve(const Matrix &matrix, long long cnt) {
    if (cnt == 1) {
        return matrix;
    }

    Matrix half = solve(matrix, cnt / 2);
    if (cnt % 2 == 1) {
        return square_matrix(square_matrix(half, half), matrix);
    } else {
        return square_matrix(half, half);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Matrix matrix = {{4, -1}, {1, 0}};
    long long n;
    cin >> n;

    if (n % 2 == 1) {
        cout << 0 << '\n';
        return 0;
    } else if (n == 2) {
        cout << 3 << '\n';
        return 0;
    }

    Matrix result = solve(matrix, n / 2 - 1);
    cout << (result[0][0] * 3 + result[0][1]+MOD) % MOD << '\n';

    return 0;
}

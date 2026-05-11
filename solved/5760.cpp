#include <iostream>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;
ll N;

typedef struct Mat {
    ll arr[2][2];
} Mat;

Mat matrixMul(Mat& a, Mat& b) {
    Mat result;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.arr[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result.arr[i][j] += (a.arr[i][k] * b.arr[k][j]) % MOD;
                result.arr[i][j] = (result.arr[i][j] + MOD) % MOD;
            }
        }
    }
    return result;
}

Mat I = {{{1, 0}, {0, 1}}};

Mat matrixPower(Mat& a, ll n) {
    if (n == 0) {
        return I;
    }
    if (n == 1) {
        return a;
    }

    Mat subMat = matrixPower(a, n / 2);
    Mat result = matrixMul(subMat, subMat);
    if (n % 2 == 1) {
        result = matrixMul(result, a);
    }
    return result;
}

void solve() {
    if (N % 2 == 1) {
        cout << 0;
        return;
    }

    Mat A = {{{4, -1}, {1, 0}}};
    ll k = N / 2;
    Mat B = matrixPower(A, k - 1);
    ll result = ((B.arr[1][0] * 11) % MOD + (B.arr[1][1] * 3) % MOD) % MOD;
    result = (result + MOD) % MOD;
    cout << result;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    solve();
}
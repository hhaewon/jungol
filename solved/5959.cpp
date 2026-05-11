#include <iostream>
using namespace std;
typedef long long ll;

int H, W;
string S[3000];
ll dpO[3000][3000];
ll dpI[3000][3000];
ll result;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    for (int i = 0; i < H; i++) {
        dpO[i][W - 1] = 0;
        for (int j = W - 2; j >= 0; j--) {
            dpO[i][j] = dpO[i][j + 1];
            if (S[i][j + 1] == 'O') {
                dpO[i][j]++;
            }
        }
    }
    for (int j = 0; j < W; j++) {
        dpI[H - 1][j] = 0;
        for (int i = H - 2; i >= 0; i--) {
            dpI[i][j] = dpI[i + 1][j];
            if (S[i + 1][j] == 'I') {
                dpI[i][j]++;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'J') {
                result += dpO[i][j] * dpI[i][j];
            }
        }
    }

    cout << result;
}
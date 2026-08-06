#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int board[1024][1024];
void func(int y, int x, int size) {
    bool flag = true;
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (board[i][j] != board[y][x]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            break;
        }
    }

    if (flag) {
        cout << board[y][x];
        return;
    }
    cout << 'X';
    int nsize = size / 2;
    func(y, x, nsize);
    func(y, x + nsize, nsize);
    func(y + nsize, x, nsize);
    func(y + nsize, x + nsize, nsize);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    func(0, 0, N);
}
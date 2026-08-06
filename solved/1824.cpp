#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool row[9][10];
bool col[9][10];
bool unit[3][3][10];
int board[9][9];
bool finished = false;
bool fix[9][9];
void go(int x, int y) {
    if (finished) {
        return;
    }

    int nx, ny;
    if (y < 8) {
        nx = x;
        ny = y + 1;
    } else {
        nx = x + 1;
        ny = 0;
    }

    if (fix[x][y]) {
        go(nx, ny);
        return;
    }

    if (x == 9) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        finished = true;
        return;
    }

    for (int i = 1; i <= 9; i++) {
        if (!row[x][i] && !col[y][i] && !unit[x / 3][y / 3][i]) {
            board[x][y] = i;
            row[x][i] = true;
            col[y][i] = true;
            unit[x / 3][y / 3][i] = true;
            go(nx, ny);
            row[x][i] = false;
            col[y][i] = false;
            unit[x / 3][y / 3][i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j]) {
                row[i][board[i][j]] = true;
                col[j][board[i][j]] = true;
                unit[i / 3][j / 3][board[i][j]] = true;
                fix[i][j] = true;
            }
        }
    }

    go(0, 0);
}
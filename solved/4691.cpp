#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int H, W;
int kr, kc;

bool visited[1000][1000];
int board[1000][1000];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> H >> W;
    cin >> kr >> kc;
    kr = kr - 1;
    kc = kc - 1;
    queue<pair<int, int>> q;
    visited[kr][kc] = true;
    q.push({kr, kc});
    board[kr][kc] = 0;

    while (!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if (0 <= nx && nx < H && 0 <= ny && ny < W && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                board[nx][ny] = board[curX][curY] + 1;
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (visited[i][j]) {
                cout << board[i][j] << " ";
            } else {
                cout << -1 << " ";
            }
        }
        cout << "\n";
    }
}

// index 0부터 시작인지 1부터 시작인지 확인
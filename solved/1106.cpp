#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N, M;
int R, C, S, K;

const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int d[101][101];
bool visited[101][101];
queue<pair<int, int>> q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    cin >> R >> C >> S >> K;

    q.push({R, C});
    d[R][C] = 0;
    visited[R][C] = true;
    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && !visited[nx][ny]) {
                d[nx][ny] = d[cx][cy] + 1;
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    cout << d[S][K];
}
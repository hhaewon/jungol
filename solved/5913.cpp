#include <iostream>
using namespace std;

int N, M;

bool graph[501][501];
bool visited[501];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    cin >> M;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    for (int i = 1; i <= N; i++) {
        if (!graph[1][i]) {
            continue;
        }
        visited[i] = 1;
        for (int j = 1; j <= N; j++) {
            if (graph[i][j]) {
                visited[j] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 2; i <= N; i++) {
        if (visited[i]) {
            cnt++;
        }
    }
    cout << cnt;
}
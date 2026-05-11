#include <bits/stdc++.h>
using namespace std;

int n;

typedef struct {
    int s;
    int w;
    int h;
    int n;
} block;

bool compare(block& a, block& b) {
    if (a.s != b.s) {
        return a.s < b.s;
    }
    return a.w < b.w;
}

block arr[100];
int dp[100];
int par[100];
int blocks[100];

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    int s, h, w;
    for (int i = 0; i < n; i++) {
        cin >> s >> h >> w;
        block b = {s, w, h, i + 1};
        arr[i] = b;
    }
    sort(arr, arr + n, compare);
    for (int i = 0; i < n; i++) {
        dp[i] = arr[i].h;
        par[i] = -1;
        for (int j = 0; j < i; j++) {
            if (arr[j].w <= arr[i].w) {
                if (dp[j] + arr[i].h > dp[i]) {
                    par[i] = j;
                    dp[i] = dp[j] + arr[i].h;
                }
            }
        }
    }

    int maxHeight = -1;
    int maxIndex = -1;
    for (int i = 0; i < n; i++) {
        if (dp[i] > maxHeight) {
            maxHeight = dp[i];
            maxIndex = i;
        }
    }

    int block = maxIndex;
    blocks[0] = arr[block].n;
    int i = 1;
    while (par[block] != -1) {
        block = par[block];
        blocks[i] = arr[block].n;
        i++;
    }
    cout << i << "\n";
    for (int j = i - 1; j >= 0; j--) {
        cout << blocks[j] << "\n";
    }
}

// dp[i] = dp[j] + arr[i].h;이다. dp[i] = dp[j] + arr[j].h 아니다. 조건문 안바꿔서 한 번
// 구조체 만들자
// 작은 거부터 생각하자. 뭔가 증가해야 하는 조건이 있고, 어떤 요소의 합을 최대화하려면 LIS를 이용한다.
// LIS 복원은 par을 이용해 전 거를 기억하면 된다.
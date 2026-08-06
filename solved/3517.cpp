#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int a[500000];
int Q;

int binarySearch(int start, int end, int v) {
    if (start > end) {
        return -1;
    }
    int mid = (start + end) / 2;
    if (a[mid] == v) {
        return mid;
    } else if (a[mid] < v) {
        return binarySearch(mid + 1, end, v);
    } else {
        return binarySearch(start, mid - 1, v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int b;
        cin >> b;
        cout << binarySearch(0, N - 1, b) << " ";
    }
}
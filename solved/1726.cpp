#include <iostream>
using namespace std;

const int MAX = 50000;

int maxTree[MAX * 4];
int arr[MAX + 1];
int N, Q;

int maxInit(int start, int end, int node)
{
    if (start == end)
    {
        return maxTree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return maxTree[node] = max(maxInit(start, mid, node * 2), maxInit(mid + 1, end, node * 2 + 1));
}

int maxQuery(int start, int end, int node, int left, int right)
{
    if (left > end || right < start)
    {
        return 0;
    }
    if (left <= start && end <= right)
    {
        return maxTree[node];
    }
    int mid = (start + end) / 2;
    return max(maxQuery(start, mid, node * 2, left, right), maxQuery(mid + 1, end, node * 2 + 1, left, right));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    maxInit(1, N, 1);
    for (int i = 0; i < Q; i++)
    {
        int A, B;
        cin >> A >> B;
        cout << maxQuery(1, N, 1, A, B) << "\n";
    }
}
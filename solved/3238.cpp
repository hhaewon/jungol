#include <iostream>
using namespace std;

const int MAXN = 100000;
const int MINNUM = -1e9 - 1;

int tree[MAXN * 4];
// int arr[MAXN + 1];
int N, M;

int init(int start, int end, int node)
{
    if (start == end)
    {
        return tree[node] = MINNUM;
    }
    int mid = (start + end) / 2;
    init(start, mid, node * 2);
    init(mid + 1, end, node * 2 + 1);
    return tree[node] = MINNUM;
}

int query(int start, int end, int node, int left, int right)
{
    if (left > end || right < start)
    {
        return MINNUM;
    }
    if (left <= start && end <= right)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return max(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
}

int update(int start, int end, int node, int index, int value)
{
    if (index < start || index > end)
    {
        return tree[node];
    }
    if (start == end)
    {
        return tree[node] = value;
    }
    int mid = (start + end) / 2;
    return tree[node] = max(update(start, mid, node * 2, index, value), update(mid + 1, end, node * 2 + 1, index, value));
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    // for (int i = 1; i <= N; i++)
    // {
    //     arr[i] = MINNUM;
    // }
    init(1, N, 1);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b;
        if (a == 1)
        {
            cin >> c;
            // arr[b] = c;
            update(1, N, 1, b, c);
        }
        if (a == 2)
        {
            cin >> c;
            int v1 = query(1, N, 1, b, c);
            if (v1 != MINNUM)
            {
                cout << v1 << "\n";
            }
        }
        if (a == 3)
        {
            // arr[b] = MINNUM;
            update(1, N, 1, b, MINNUM);
        }
    }
}
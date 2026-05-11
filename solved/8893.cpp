#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> M2;

const int MOD = 1e9 + 7;

M2 matrixMul(M2 &A, M2 &B)
{
    M2 result(2, vector<ll>(2));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                result[i][j] = (result[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
            }
        }
    }
    return result;
}

M2 matrixPower(M2 &A, ll n)
{
    if (n == 1)
    {
        return A;
    }
    if (n == 0)
    {
        M2 I(2, vector<ll>(2));
        I[0][0] = 1;
        I[0][1] = 0;
        I[1][0] = 0;
        I[1][1] = 1;
        return I;
    }
    M2 subMatrix(2, vector<ll>(2));
    subMatrix = matrixPower(A, n / 2);
    M2 temp(2, vector<ll>(2));
    temp = matrixMul(subMatrix, subMatrix);
    if (n % 2 == 0)
    {
        return temp;
    }
    else
    {
        return matrixMul(temp, A);
    }
}

void solve(ll n)
{
    M2 M(2, vector<ll>(2));
    M[0][0] = 1;
    M[0][1] = 1;
    M[1][0] = 1;
    M[1][1] = 0;

    M2 result(2, vector<ll>(2));
    result = matrixPower(M, n);
    cout << result[1][0] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    while (n != -1)
    {
        solve(n);
        cin >> n;
    }
}
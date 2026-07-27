N = int(input())
a = list(map(int, input().split()))[::-1]
b = [0] * (N+1)
c = [0] * (N+1)

b[0] = 1
c[0] = 0

b[1] = a[0] * b[0] + c[0]
for i in range(2, N+1):
    c[i-1] = b[i-2]
    b[i] = a[i-1]*b[i-1] + c[i-1]

A = b[N]
B = b[N-1]

print(A-B, A)
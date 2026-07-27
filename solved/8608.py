import sys
import bisect

input = sys.stdin.readline
print = sys.stdout.write

N, K, C = map(int, input().rstrip().split())
A = list(map(int, input().rstrip().split()))
s = [0] * N
A.sort()
s[0] = A[0]

for i in range(1, N):
    s[i] = s[i-1]+A[i]

answers = []

def lowerBound(s, x):
    start = 0
    end = N
    while (start < end) :
        mid = (start+end)//2
        if s[mid] <= x:
            start = mid+1
        else:
            end = mid

    return end

for x in range(1, C+1):
    l = bisect.bisect_right(s, x)
    if N <= K:
        answers.append(str(s[N-1]))
    else:
        if l == 0:
            answers.append(str(s[K-1]))
        elif N-l >= K:
            answers.append(str(s[l+K-1]-s[l-1]))
        else:
            answers.append(str(s[N-1]-s[N-K-1]))
print("\n".join(answers))
N = int(input())
M = int(input())

graph = [[] for _ in range(N+1)]
total_need = [0] * (N+1)
for _ in range(M):
    X, Y, K = map(int, input().split())
    graph[X].append((Y, K))

def solve(node, num):
    if not graph[node]:
        total_need[node] += num
    else:
        for subnode, subnum in graph[node]:
            solve(subnode, num*subnum)

solve(N, 1)

for i in range(1, N+1):
    if total_need[i]:
        print(f"{i} {total_need[i]}")



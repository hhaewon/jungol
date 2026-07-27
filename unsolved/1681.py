N = int(input())

cost = [list(map(int, input().split())) for _ in range(N)]
cur_cost = 0
min_cost = 10000
visited = [False]*(N+1)
visited[1] = True


def dfs(index, prev):
    global cur_cost, min_cost
    if index == N:
        cur_cost += cost[prev-1][1-1]
        min_cost = min(min_cost, cur_cost)
        cur_cost -= cost[prev-1][1-1]
        return

    if cur_cost >= min_cost:
        return
    
    for i in range(2, N+1):
        if not visited[i] and cost[prev-1][i-1]:
            visited[i] = True
            cur_cost += cost[prev-1][i-1]
            dfs(index+1, i)
            visited[i] = False
            cur_cost -= cost[prev-1][i-1]

dfs(1, 1)

print(min_cost)
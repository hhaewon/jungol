N = int(input())
cnt = 0
samex = [False] * N
samey = [False] * N
samediag1 = [False] * (2*N-1)
samediag2 = [False] * (2*N-1)

def return_param(x, y):
    return (x, y, (y-x)+N-1, x+y)

def dfs(index):
    global cnt
    if index == N:
        cnt += 1
        return
    
    for x in range(0, N):
        p1, p2, p3, p4 = return_param(x, index)
        if not samex[p1] and not samey[p2] and not samediag1[p3] and not samediag2[p4]:
            samex[p1] = samey[p2] = samediag1[p3] = samediag2[p4] = True
            dfs(index+1)
            samex[p1] = samey[p2] = samediag1[p3] = samediag2[p4] = False


dfs(0)
print(cnt)
# data = [0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712] 걍 구하고 냈다.
# python 느려서 최대한 최적화 해야 한다. 상수시간도 문제 된다.
N = int(input())
board = [list(input().strip()) for _ in range(N)]
row = [False] * N
col = [False] * N
cnt = 0

def solve(index, x, y):
    global cnt
    if (index == N-1):
        cnt += 1
        return
    
    for i in range(N):
        if (row[i]):
            continue

        for j in range(N):
            if (N*x+y < N*i+j and board[i][j] == '.' and not col[j]):
                row[i] = True
                col[j] = True
                solve(index+1, i, j)
                row[i] = False
                col[j] = False

for j in range(N):
    if (board[0][j] == '.'):
        row[0] = True
        col[j] = True
        board[0][j] = '#'
        solve(0, 0, j)
        row[0] = False
        col[j] = False
            
print(cnt)
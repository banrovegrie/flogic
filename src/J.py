n = int(input())
graph = [[] for _ in range(n)]
    
for i in range(n * (n - 1) // 2):
    x, y, v = map(int, input().split())
    graph[x - 1].append(v)
    graph[y - 1].append(v)

ans = 0
for i in range(n):
    graph[i].sort()
    for j in range(1, len(graph[i]), 2):
        ans += graph[i][j]

print(ans)
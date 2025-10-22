from collections import defaultdict

n = int(input())
graph = defaultdict(list)


def dfs(u, parent):
    val = 0
    for v in graph[u]:
        if parent == v:
            continue
        val += dfs(v, u)
    return val - 1 if val else val + 1


for _ in range(n-1):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

if dfs(1, 1):
    print("Alice")
else:
    print("Bob")

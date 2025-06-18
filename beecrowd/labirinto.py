def dfs(adj, node, dp):
    if(dp[node] != -1):
        return dp[node]
    dp[node] = 0
    if len(adj[node]) == 0:
        return 0
    contador = 0
    for i in adj[node]:
        if dp[i] == -1:
            contador += dfs(adj, i, dp) + 2
        dp[node] = contador
    return contador

t = int(input())

while t > 0:
    t -= 1
    begin = int(input())
    n,m = map(int,input().split())
    adj = [[] for _ in range(n)]
    for i in range(m):
        u,v = map(int,input().split())
        adj[u-1].append(v-1)
        adj[v-1].append(u-1)
    dp = [-1 for _ in range(n)]
    resultado = dfs(adj, begin-1, dp)
    print(resultado)



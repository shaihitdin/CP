inf = open("warp.in", "r")
ouf = open("warp.out", "w")

ans = 0
n, m = map (int, inf.readline().split() )

d = {}
temp = 1
for i in range (1, 101):
    temp = temp * 9
for i in range (1, n + 1):
    for j in range (1, n + 1):
        d[i, j] = temp

for i in range (1, n + 1):
    d[i, i] = 1
for i in range (1, m + 1):
    x, y, c  = map (int, inf.readline().split() )
    d[x, y] = min (d[x, y], c)
    d[y, x] = min (d[y, x], c)
for k in range (1, n + 1):
    for i in range (1, n + 1):
        for j in range (1, n + 1):
        	d[i, j] = min (d[i, j], d[i, k] * d[k, j])
for i in range (1, n + 1):
    for j in range (1, n + 1):
        ans = max (ans, d[i, j])
print (ans, file = ouf)
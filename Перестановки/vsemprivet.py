p = [[1,2,3,0],[1,2,0,4,3],[0,1,2,3,4],[1,0,2,3,4]]
for x in p:
    n, v, k = len(x), [0]*len(x), 0
    for i in range(n):
        if not v[i]: 
            k += 1
            while not v[i]: v[i], i = 1, x[i]
    print(f"{x} → {n}-{k}={n-k}")
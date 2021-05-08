n,s = map(int,input().split())
c = [0]
for i in range(n):
    cur = int(input())
    c.append(cur)

m1 = [1e9 for i in range(n+1)]
m2 = [1e9 for i in range(n+2)]

for i in range(1,n+1):
    m1[i]=min(m1[i-1],c[i])

for i in reversed(range(1,n+1)):
    m2[i]=min(m2[i+1],c[i])

best = -1

for i in range(1,n+1):
    cur=min(m1[i]+(n-1)*s-(i-1), m2[i]-i*s)
    best=max(cur,best)

print(best)

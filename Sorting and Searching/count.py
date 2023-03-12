from random import shuffle, randint
def cnt(vv):
    c=1
    for i in range(1, len(vv)-1):
        if(vv[i+1] < vv[i]):
            c+=1
    print(c)
    return c

n, q = input().split()
n = int(n)
q = int(q)
#v = input().split()
#v = [int(y) for y in v]
#vv = [0]*(n+1)

#for i in range(len(v)):
#    vv[v[i]] = i+1


x = [i+1 for i in range(n)]
shuffle(x)
for i in range(q):
    print(x)
    a = randint(1, n)
    b = randint(1, n)
    c = x.index(a)
    d = x.index(b)
    t = x[c]
    x[c] = x[d]
    x[d] = t
    cnt(x)


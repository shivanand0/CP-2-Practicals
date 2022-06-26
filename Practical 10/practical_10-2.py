# (2/3/4)-D Sqr/Rects/Cubes/Boxes?

n = int(input())

a = int(n*(n+1)*(2*n+1)/6)
b = int((n+1)*n/2*(n+1)*n/2 - a) 
c = int(n*(n+1)/2*n*(n+1)/2)
d = int((n+1)*n/2*(n+1)*n/2*(n+1)*n/2 - c) 
e = 0
for i in range(1,n+1): 
    e += i*i*i*i
f = int((n+1)*n/2*(n+1)*n/2*(n+1)*n/2*(n+1)*n/2 - e) 
print(a,b,c,d,e,f)

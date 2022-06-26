# The Powerpuff Girls

import math

n = int(input())
list1 = input().split() 
list2 = input().split() 
l1 = []
l2 = []

for i in list1: 
    l1.append(int(i))
for i in list2: 
    l2.append(int(i))

l3 = []

for i in range(n): 
    l3.append(math.floor(l2[i]/l1[i]))
ind = l1.index(max(l1)) 
ans = l3[ind]

for i in range(n-1): 
    l1.pop(ind) 
    l3.pop(ind)
    if(ans > l3[l1.index(max(l1))]): 
        ind = l1.index(max(l1))
        ans = l3[ind] 
    else:
        ind = l1.index(max(l1)) 
        
print(ans)
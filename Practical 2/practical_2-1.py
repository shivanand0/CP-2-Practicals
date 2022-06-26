# summation of four primes

d1=[]
d2=[]

def IsPrime(n):
    for i in range(2,int(n**0.5)+1): 
        if (n%i==0):
            return False
    return True


a=int(input("Enter the number")) 
for i in range (2,500):
    if(IsPrime(i)):
        d1.append(i)
#print(d1) 
count=1 
flag=0 
if(a<=7):
    print("Impossible");
else:
    while count:
        for i in d1:
            if(count==0):
                break;

            for j in d1:
                if(count==0):
                    break; 
                for k in d1:
                    if(count==0):
                        break; 
            
                    for l in d1:
                        if(count==0):
                            break; 

                        if(i+j+k+l==a):
                            count=0 
                            d2.append(i) 
                            d2.append(j) 
                            d2.append(k) 
                            d2.append(l)

print(d2) 
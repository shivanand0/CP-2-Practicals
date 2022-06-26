#include<stdio.h>
long long int fact(long long int no)
{
    long long int i=1,f=1; 
    while(i<=no)
    {
        f=i*f; i++;
    }
    return f;
}

int main()
{
    long long int a,b,fact1=0; printf("enter 2 nos :"); 
    scanf("%lld %lld",&a,&b); fact1=fact(a); 
    
    if(fact1%b==0)
        printf("%lld divides %lld! \n",b,a);
    else
        printf("%lld does not divides %lld! \n ",b,a);
}

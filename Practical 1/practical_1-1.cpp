//Light More Light
#include<cstdio> 
#include<cmath>

int main()
{
    long long int number;

    while(scanf("%lld",&number) == 1)
    {
        if(number == 0) 
            break;
        else
        {
            long long int temp = sqrt(number); temp *=temp;
            if(temp == number) 
                printf("yes\n");
            else 
                printf("no\n");
        }
    }

    return 0;
}


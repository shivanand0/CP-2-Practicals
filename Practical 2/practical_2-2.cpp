// Smith numbers

#include <bits/stdc++.h>
using namespace std; 
vector<int> get_primes() {
    vector<int> primes;
    vector<bool> sieve(100000, true);

    for (int i = 2; i < 100000; i++) 
    { 
        if (sieve[i]) {
            primes.push_back(i); 
            int j = 2;

            while (i * j < 100000) 
            { 
                sieve[i * j] = false;
                j++;
            }
        }
    }
    return primes;
}

int sum_of_digits(int n) 
{ 
    int sum = 0;
    while (n) 
    {
        sum += n % 10; n /= 10;
    }
    return sum;
}

int main() 
{
    vector<int> primes = get_primes(); 
    int T;
    scanf("%d", &T);

    while (T--) 
    { 
        int N;
        scanf("%d", &N);

        while (true) 
        { 
            N++;
            int sum = sum_of_digits(N); 
            int prime_sum = 0;

            int temp = N, index = 0; int factors = 0;

            while (temp > 1 && primes[index] <= sqrt(temp)) 
            { 
                if (temp % primes[index] == 0) 
                {
                    prime_sum += sum_of_digits(primes[index]); 
                    temp /= primes[index];
                    factors++;
                }
                else
                    index++;
            }
            
            if (temp != 1) 
                prime_sum += sum_of_digits(temp); factors += 1;

            if (sum == prime_sum && factors > 1) 
            { 
                printf("%d\n", N);
                break;
            }
        }
    }
}



/*
JAVA 


import java.util.Scanner;
import java.util.ArrayList;
public class SmithNumber {
    static int getAddition(int num) {
        int digit, sum = 0;
        while (num > 0) {
            // last digit of num
            digit = num % 10;
            sum = sum + digit;
            num = num / 10;
        }
        // System.out.println("num sum: "+sum);
        return sum;
    }

    // Following are the steps to find all prime factors.
    // 1) While n is divisible by 2, print 2 and divide n by 2.
    // 2) After step 1, n must be odd. Now start a loop from i = 3 to the square
    // root of n. While i divides n, print i, and divide n by i. After i fails to
    // divide n, increment i by 2 and continue.
    // 3) If n is a prime number and is greater than 2, then n will not become 1 by
    // the above two steps. So print n if it is greater than 2.

    //function to find prime factores of a number
    static int primeFactors(int num)
    {
        ArrayList<Integer> factorsArrList = new ArrayList<Integer>();

        int sum = 0;

        while(num%2 == 0)
        {
            // System.out.println(2+ " *1 ");
            factorsArrList.add(2);
            num /= 2;
        }

        for (int i=3; i <= Math.sqrt(num); i+=2)
        {
            while(num%i == 0)
            {
                // System.out.println(i+ " *2 ");
                factorsArrList.add(i);
                num /= i;
            }
        }

        if(num > 2)
            factorsArrList.add(num);

        for (int i = 0; i < factorsArrList.size(); i++) {
            // System.out.println(factorsArrList.get(i));
            sum = getAddition(factorsArrList.get(i)) + sum;
        }
        
        // System.out.println("factors sum: "+sum);
        return sum;
    }
    public static void main(String[] args) {
        int num = 4937770;
        boolean check=true;

        while(check)
        {
            System.out.println(num);
            int addition = getAddition(num);
            int addition2 = primeFactors(num);

            if(addition == addition2)
            {
                System.out.println(num+" is a Smith Number");
                check = false;
                break;
            }
            else
            {
                ++num;
            }

        }
        // int addition = getAddition(num);
        // // System.out.println(addition);
        // int addition2 = primeFactors(num);

        // if(addition == addition2)
        //     System.out.println(num+" is a Smith Number");
        // else
        // {
        //     int newNum = num++;
        // }
    }
}


*/